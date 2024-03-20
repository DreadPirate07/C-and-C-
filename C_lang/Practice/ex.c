#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
};
int main()
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = 9;
    struct Node *ptr2 = ptr;
    free(ptr2);
    printf("\n%p \n%d\n", ptr, ptr2->data);
}