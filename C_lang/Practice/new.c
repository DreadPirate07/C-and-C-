#include<stdio.h>

int main()
{
    int a, b, sum;
    
    printf("Enter two numbers: ");
    
    // taking two numbers input from the user
    scanf("%d%d", &a, &b);
    
    sum = a + b;
    
    // printing the sum of two numbers in the output
    printf("Sum of %d and %d: %d", a, b, sum);
    
    return 0;
}
