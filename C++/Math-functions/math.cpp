#include <iostream>
#include "arr.h"

double arrayAverage(struct arr &a)
{
    double sum = 0;

    for (int i = 0; i < a.size; i++)
    {
        sum += a.arr[i];
    }
    return sum / ((double)a.size);
}