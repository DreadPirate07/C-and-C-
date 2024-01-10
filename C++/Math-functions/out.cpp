#include <iostream>
#include "arr.h"

void printarr(struct arr &a)
{
    for (int i = 0; i < a.size; i++)
    {
        std::cout << a.arr[i] << " ";
    }
    std::cout << std::endl;
}