#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/types.h>
int main(int argc, char *argv[])
{
    int fd = open("/home/dreadpirate/CodingPirate/C and C++/C_lang/filesys.txt",
                  O_WRONLY | O_CREAT | O_TRUNC);
    //printf("%d \n", fd);
    assert(fd != -1);
    // The assert macro in C is a debugging aid that tests a given expression and terminates the program if the expression is false. It is typically used during development to catch programming errors early.
    int rc = write(fd, "hello world\n", 13);
    assert(rc != -1);
    close(fd);
    return 0;
    }