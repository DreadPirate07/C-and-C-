// the fork() call creates and exact replica of the parent process.
// the code starts to run concurrently, ie the parent and the child code.
// the rc value stores the child proccess pid
// the rc value for the child process would be 0 and for the parent process
// it will be the child process pid.
// since 2 programs start to run simultaneously that's why the messages are logged two times 
// in the output.
// the difference in the rc value for the child and parent is useful, it allows the differentiation
// of processes for the parent and child code.



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
        printf("Parent of PID %d is %d \n", rc, (int)getpid());
    }
    printf("This line is a proof that the code has reached the end \n");
    return 0;
}