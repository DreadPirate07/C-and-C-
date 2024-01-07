#include<stdlib.h>
#include<stdio.h>

int main(){
    int *ptr;

    ptr = (int*)malloc(5*sizeof(int));
    if (ptr!=NULL) printf("Memory successfully created! \n");
    // printf("ptr address = %d \n",ptr);
    // printf("ptr+1 address = %d \n",(ptr+1));
    // printf("ptr+2 address = %d \n",(ptr+2));
    *(ptr) = 5,*(ptr+1) = 6,*(ptr+2) = 7,*(ptr+3) = 8,*(ptr+4)= 9;
    // printf("%d %d \n",*(ptr),*(ptr+1));
    for (int i = 0 ; i < 5; i++){
        printf("%d ",ptr[i]);
    }
    printf("\n");
    return 0;
}