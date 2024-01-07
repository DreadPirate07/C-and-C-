#include <stdio.h>
#include<stdlib.h>

// calloc takes two arguments calloc(no of elements, size of each element in bytes);

int main(){
    int *ptr = calloc(2,sizeof(char));
    if (ptr!=NULL) printf("memory allocatec successfully \n");
    *(ptr) = 5,*(ptr+1)=6;
    printf("%d %d \n",*ptr,*(ptr+1));
    printf("%d \n",((char*)5));
    printf("%d",sizeof((char*)5));
    return 0;
}