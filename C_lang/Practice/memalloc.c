#include <stdio.h> #include <stdlib.h>
#pragma warn - rvl
#pragma warn - rch
#pragma warn - par

int main()
{
    printf("%ld \n", sbrk(0));
    printf("%ld", sbrk(1));
}