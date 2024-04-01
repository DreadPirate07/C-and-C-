#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 65432

int connect_to_server(const char *server_ip, int port)
{
    int sock;
    struct sockaddr_in server_addr;

    // Creating socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket creation error");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    // Convert IPv4 or IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0)
    {
        printf("\nInvalid address/Address not supported \n");
        return -1;
    }

    // Connecting to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    return sock;
}

void execute_jobs(int sock)
{
    while (1)
    {
        // Simulate receiving a job assignment (in a real application, there would be actual data received from the server)
        printf("Simulating job execution...\n");
        sleep(5); // Simulating job execution by sleeping for 5 seconds

        // Reporting job completion to the server
        char *message = "Node: Job completed";
        if (send(sock, message, strlen(message), 0) < 0)
        {
            perror("Send failed");
            break;
        }

        // Waiting for acknowledgment or new job (for simplicity, we assume an immediate response)
        char buffer[1024] = {0};
        if (read(sock, buffer, sizeof(buffer)) < 0)
        {
            perror("Read failed");
            break;
        }
        printf("Server says: %s\n", buffer);

        // For the sake of this example, let's assume the client will terminate after completing one job cycle
        // In a real scenario, this loop could continue until all jobs are completed or the server sends a termination signal
        break;
    }
}

int main()
{
    int sock = connect_to_server(SERVER_IP, SERVER_PORT);
    if (sock < 0)
    {
        return -1;
    }

    execute_jobs(sock);

    close(sock);
    return 0;
}
