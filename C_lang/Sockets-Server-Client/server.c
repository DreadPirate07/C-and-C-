#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 65432
#define MAX_CLIENTS 10
#define TOTAL_JOBS 100

typedef enum
{
    NOT_STARTED,
    IN_PROGRESS,
    COMPLETED
} job_status_t;

typedef struct
{
    int job_id;
    job_status_t status;
    int assigned_node;
} job_t;

typedef struct
{
    int node_id;
    int socket;
} node_t;

job_t jobs[TOTAL_JOBS];
node_t node[MAX_CLIENTS];
int job_counter = 0;

pthread_mutex_t job_lock;

void *client_handler(void *sock_desc)
{
    int sock = *(int *)sock_desc;
    int read_size;
    char client_msg[1000];

    while ((read_size = recv(sock, client_msg, 1000, 0)) > 0)
    {
        client_msg[read_size] = '\0';
        int node_fetched_id, completed_jobs;
        sscanf(client_msg, " Node %d: %d jobs completed", &node_fetched_id, &completed_jobs);
        printf("Recieved from node %d : %d jobs completed \n", node_fetched_id, completed_jobs);

        pthread_mutex_lock(&job_lock);
        for (int i = 0; i < TOTAL_JOBS; i++)
        {
            if ((jobs[i].assigned_node == node_fetched_id) && (jobs[i].status = IN_PROGRESS))
            {
                if (completed_jobs <= 0)
                    break;
                jobs[i].status = COMPLETED;
                completed_jobs--;
            }
        }
        pthread_mutex_unlock(&job_lock);
    }
    if (read_size == 0)
        printf("Client Disconnected");
    else if (read_size < 0)
        printf("Process Failed");
    free(sock_desc);
}

int main()
{
    int server_fd, new_socket, *new_sock;
    struct sockaddr_in server, client;
    int c = sizeof(struct sockaddr_in);

    pthread_mutex_init(&job_lock, NULL);
    initialize_jobs();

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
    {
        perror("Could not create socket");
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("bind failed");
        return 1;
    }

    listen(server_fd, 3);
    puts("Waiting for incoming connections...");

    while ((new_socket = accept(server_fd, (struct sockaddr *)&client, (socklen_t *)&c)))
    {
        puts("Connection accepted");

        pthread_t sniffer_thread;
        new_socket = malloc(1);
        *new_sock = new_socket;

        if (pthread_create(&sniffer_thread, NULL, client_handler, (void *)new_sock) < 0)
        {
            perror("could not create thread");
            return 1;
        }

        puts("Handler assigned");
    }

    if (new_socket < 0)
    {
        perror("accept failed");
        return 1;
    }

    return 0;
}
