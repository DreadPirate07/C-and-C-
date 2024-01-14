#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    printf("Hello World, The PID of current program:%d \n", getpid());
    int rc = fork();

    if (rc == -1)
        fprintf(stderr, "Error while creating a fork \n");
    else if (rc == 0)
    {
        printf("Child PID : %d \n", getpid());
        char *args[3];
        args[0] = strdup("/home/dreadpirate/CodingPirate/C and C++/C_lang/OpSys/execsyscall");
        args[1] = strdup("syscallExpFile.c");
        args[3] = NULL;
        int execall = execvp(args[0], args);
        if (execall == -1)
        {
            fprintf(stderr, "Exe call not successfull \n");
            exit(1);
        }
    }
    else
    {
        wait(NULL);
        printf("Parent PID : %d", getpid());
    }
    return 0;
}