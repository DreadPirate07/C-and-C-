#include<stdio.h>
#include<stdlib.h>

struct node{
    int id;
    struct node *next;
};

struct node *head;

void deletebeggining(){
    struct node *ptr;
    ptr = head;
    head = ptr->next;
    free(ptr);
    printf("node successfully deleted \n");
}
void insertnode(struct node* a){
    struct node* temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) printf("Overflow");
    else printf("memory successfully created \n");
    temp = a;
    while (temp->next !=NULL){
        temp = temp->next;
    }
    struct node *insertvalue;
    insertvalue = (struct node *)malloc(sizeof(struct node));
    if (insertvalue == NULL) printf("Overflow");
    else printf("memory successfully created \n");
    int x;
    scanf("%d \n",&x);
    insertvalue->id=x;
    temp->next = insertvalue;
    printf("Node successfully inserted into memory\n \n");
}

void insertbefore(struct node *headptr){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) printf("Overflow");
    else printf("memory successfully created \n");
    int x;
    scanf("%d",&x);
    temp->id = x;
    temp->next = headptr;
    head = temp;
    printf("Node successfully inserted \n \n");

}

void printlist(struct node *a){
    if (a==NULL) printf("Node empty!");
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp = a;
    while (temp->next != NULL){
        printf("%d \n",temp->id);
        temp = temp->next;
    }
    printf("%d \n",temp->id);
}

int main(){
    // struct node *a;
    // struct node *b;
    // struct node *c;
    // struct node *temp;
    // temp = (struct node*)malloc(sizeof(struct node));
    // temp->id = 5;
    // temp->next = NULL;
    // a = temp;
    // temp = (struct node*)malloc(sizeof(struct node));
    // temp->id = 6;
    // temp->next = NULL;
    // b = temp;
    // a->next = b;
    // temp = (struct node*)malloc(sizeof(struct node));
    // temp->id = 7;
    // c = temp;
    // b->next = c;
    // // free(temp);
    // // printf("%d \n",a->next->id);
    // // printf("%d",b->id);
    // insertlast(a);
    // printlist(a);
    struct node *a;
    struct node *b;
    a = (struct node *)malloc(sizeof(struct node));
    b = (struct node *)malloc(sizeof(struct node));
    //head = (struct node *)malloc(sizeof(struct node*));
    a->id  = 1;
    a->next = b;
    b->id =2 ;
    head = a;
    printf("%d \n", head->id);
    // printf("changed \n");
    insertnode(a);
    // insertnode(a); 
    printlist(head);
    deletebeggining();
    printf("%d \n", head->id);

    // printf("%d \n", head->id);
    // printf("%d \n", head->next->id);
    // printf("%d \n", head->next->next->id);
}