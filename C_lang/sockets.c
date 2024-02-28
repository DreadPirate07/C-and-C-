#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

struct in_addr
{
    unsigned long s_addr; // IPv4 address
};

struct sockaddr_in
{
    short int sin_family;    // address family, AF_INET
    unsigned short int port; // port
    struct in_addr sin_addr;
    unsigned char sin_zero[8]; // provides padding for easy casting
};

int main()
{
    struct sockaddr_in my_addr;
    struct sockaddr_in new_addr;
    my_addr.sin_family = AF_INET;
    my_addr.port = 0;
    my_addr.sin_addr.s_addr = INADDR_ANY;
    memset(&(my_addr.sin_zero), '\0', 8);

    int sockfd = socket(PF_INET, SOCK_STREAM, 0);                                      // define socket descriptor
    int bindfd = bind(sockfd, (struct sockaddr *)&(my_addr), sizeof(struct sockaddr)); // bind socket descriptor

    listen(sockfd, 10); // at max 10 connections in queue

    int sin_size = sizeof(struct sockaddr_in);

    int new_fd = accept(sockfd, (struct sockaddr *)(&new_addr), sin_size); // a new file descriptor for handling send() and recv() calls
}