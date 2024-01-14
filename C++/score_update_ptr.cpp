// create a simplepoint systemusing pointers that has the methods. The pointer being passed should be certain
// created in main method.

#include <iostream>
#include <cstdlib>

void score_update(int *p, int point)
{
    (*p) = (*p) + point;
}

void random_update(int *p)
{
    (*p) = +rand();
}

void print_pointer_memory(int *p)
{
    std::cout << p << std::endl;
}

int main()
{
    int *p = (int *)malloc(sizeof(int));
    *p = 95;
    score_update(p, 10);
    std::cout << "score updated: " << *p << std::endl;
    random_update(p);
    std::cout << "random update: " << *p << std::endl;
    print_pointer_memory(p);
}