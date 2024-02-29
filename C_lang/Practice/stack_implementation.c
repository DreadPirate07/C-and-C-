#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int data[100];
    int top;
} stack_t;

void push(struct stack *s, int val)
{

    printf("Stack address inside push function- %p \n", (void *)s);
    if ((s->top) < 100)
    {
        s->top += 1;
        (s->data[(s->top)]) = val;
    }
    else
    {
        printf("Stack Overflow, exitting");
        exit(-1);
    }
}

void pop(struct stack *s)
{
    if (s->top > 0)
    {
        (s->top) = (s->top) - 1;
    }
}

int return_top(struct stack *s)
{
    return (s->data[s->top]);
}

int main()
{
    stack_t nums;
    nums.top = 0;
    printf("Stack address - %p \n", (void *)&nums);
    int top = return_top(&nums);
    printf("Top value: %d \n", top);
    push(&nums, 5);
    top = return_top(&nums);
    printf("Top value: %d \n", top);
    push(&nums, 10);
    top = return_top(&nums);
    printf("Top value: %d \n", top);
    pop(&nums);
    top = return_top(&nums);
    printf("Top value: %d \n", top);
    pop(&nums);
    top = return_top(&nums);
    printf("Top value: %d \n", top);
    pop(&nums);
    top = return_top(&nums);
    printf("Top value: %d \n", top);
    pop(&nums);
}