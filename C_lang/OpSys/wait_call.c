//sometimes it is useful to let the child process finish first before proceeding with the parent process
// this is accomplished using that wait() system call.
// the parent process calls wait() to delay it's execution until the child finishes executing

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv)
{
    printf("Current PID - %d \n", (int)getpid());
    int rc = fork();
    printf("rc value is %d  and the pid is %d\n", rc, (int)getpid());
    if (rc == -1)
        fprintf(stderr, "Fork Process Failed \n");
    else if (rc == 0)
    {
        printf("New PID formed : %d \n", getpid());
    }
    else
    {
        // int rc_wait = wait();
        wait();
        printf("Parent of PID %d is %d \n", rc, (int)getpid());
    }
    printf("This line is a proof that the code has reached the end \n");
    return 0;
}