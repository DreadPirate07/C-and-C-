#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Location of main %p \n", main);
    printf("Location of heap %p \n", malloc(100e6));
    int x = 3;
    printf("Location of Stack %p ", &x);
}