#ifndef ARR_H
#define ARR_H
struct arr
{
    double arr[10];
    int size;
};

extern void printarr(struct arr &a);
extern double arrayAverage(struct arr &a);

#endif