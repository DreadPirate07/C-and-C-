#include <stdio.h>
#include <string.h>

struct tag
{
    char fname[40];
    char lname[40];
    int age;
    float rate;
};
struct tag my_struct;

void print_name(struct tag *p)
{
    printf("%s \n", p->fname);
    printf("%s \n", p->lname);
    printf("%d \n", p->age);
}

int main()
{
    struct tag *ptr = &my_struct;
    strcpy(my_struct.lname, "Jenson");
    strcpy(my_struct.fname, "Thomas");
    my_struct.age = 63;
    print_name(ptr);
}