#include <stdio.h>
#include <string.h>

struct tag
{
    char fname[40];
    char lname[40];
    int age;
    float rate;
};

union new_tag
{
    struct
    {
        char fname[40];
        char lname[40];
        int age;
        float rate;
    } s;
};

struct tag my_struct;

void print_name(struct tag *p)
{
    printf("%s \n", p->fname);
    printf("%s \n", p->lname);
    printf("%d \n", p->age);
}

void print_addresses(struct tag *p)
{
    printf("%p \n", &(p->fname));
    printf("%p \n", &(p->lname));
    printf("%p \n", &(p->age));
}

void print_union_addresses(union new_tag *u)
{
    printf("%p \n", (u->s.fname));
    printf("%p \n", (u->s.lname));
    printf("%p \n", (u->s.age));
    printf("%p \n", (u->s.rate));
}

int main()
{
    union new_tag my_union;
    strcpy(&(my_union.s.fname), "Hello world \n");
    printf("%s", my_union.s.fname);
    struct tag *ptr = &my_struct;
    strcpy(my_struct.lname, "Jenson");
    strcpy(my_struct.fname, "Thomas");
    my_struct.age = 63;
    print_name(ptr);
    print_addresses(ptr);
    print_union_addresses(&my_union);
}