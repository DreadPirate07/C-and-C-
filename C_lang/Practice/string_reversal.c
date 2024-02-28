// Reversing a string using stack Operation :D

#include <stdio.h>
#include <stdlib.h>
typedef struct stack stack_t;

struct stack
{
    char data[100];
    int top;
};

int empty(stack_t *p)
{
    return (p->top == -1);
}

char top(stack_t *p)
{
    return p->data[p->top];
}

void push(stack_t *p, char c)
{
    p->data[++(p->top)] = c;
}

void pop(stack_t *p)
{
    if (!empty(p))
        p->top = (p->top) - 1;
}

int main()
{
    stack_t *p = malloc(sizeof(stack_t));
    char str[] = "ABCDE";
    int i = 0;
    while (str[i] != '\0')
    {
        push(p, str[i]);
        i++;
    }
    printf("Reversing the String: \n");
    while (!empty(p))
    {
        printf("%c", top(p));
        pop(p);
    }
    printf("\n");
    return 0;
}