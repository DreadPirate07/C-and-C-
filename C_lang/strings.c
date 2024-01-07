#include<stdio.h>


int main(){
    char a[10] = "india";
    //scanf("%s",a);
    //printf("%d \n",sizeof(a));
    printf("%s \n",a);

    for(int i = 0 ; i< 10 ; i++){
        while(a[i] != '\0') {
            printf("%c \n",a[i]);
            i++;
        }
    }
}