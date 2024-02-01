#include <stdio.h>

int main()
{

    int myarr[5] = {1, 2, 3, 4, 5};
    char a[5] = "abcd";
    char *ptr = &a;
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(myarr));
        puts(ptr);
    }
}