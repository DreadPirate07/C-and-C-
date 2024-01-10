#include <iostream>
#include "arr.h"

void printarr(struct arr &a);
double arrayAverage(struct arr &a);

int main(int argc, char **argv)
{
    int i = 0;
    arr a;
    // double arr[10];
    // int sz;

    do
    {
        double tmp;
        std::cin >> tmp;

        if (tmp < 0)
        {
            a.size = i;
            break;
        }

        a.arr[i] = tmp;
        i = i + 1;
    } while (true);

    printarr(a);
    std::cout << arrayAverage(a) << std::endl;

    return 0;
}