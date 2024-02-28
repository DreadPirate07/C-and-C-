#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
} node_t;

node_t *head = NULL;

void insEnd(node_t **reference, int value)
{
    printf("Inside insEnd function \n");
    node_t *current = (node_t *)(*reference);
    while (current->next != NULL)
    {
        printf("Current Node value - %d \n", current->val);
        current = current->next;
    }
    printf("Creating New Node \n");
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    if (newNode != NULL)
        printf("Node created Successfully \n");
    newNode->val = value;
    newNode->next = NULL;
    current->next = newNode;
}

void initializeLinkedList(node_t **head, int value)
{
    *head = (node_t *)malloc(sizeof(node_t));
    if (*head != NULL)
        printf("Initial Node created Successfully. \n");
    printf("Node value - %d \n", (*head)->val);
    (*head)->val = value;
    (*head)->next = NULL;
}

void printArray(node_t **head)
{
    node_t *nodeinit = *head;
    while ((nodeinit) != NULL)
    {
        printf("%d ", nodeinit->val);
        nodeinit = nodeinit->next;
    }
}


int main()
{
    initializeLinkedList(&head, 0);
    insEnd(&head, 1);
    insEnd(&head, 2);
    insEnd(&head, 3);
    printArray(&head);
    return 0;
}