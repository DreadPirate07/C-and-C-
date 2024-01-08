#include<stdio.h>
#include <string.h>


int main(){
    char a[10] = {'I','n','d','i','a'};
    //scanf("%s",a);
    //printf("%d \n",sizeof(a));
    printf("%s \n",a);

    // for(int i = 0 ; i< 10 ; i++){
    //     while(a[i] != '\0') {
    //         printf("%c \n",a[i]);
    //         i++;
    //     }
    // }
    char b[] = "choice of ppl";
    char c[25];
    strcpy(c,a);
    strcat(c,b);
    printf("%s",c); 
}