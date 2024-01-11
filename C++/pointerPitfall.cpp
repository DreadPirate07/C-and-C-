#include <iostream>

// the returnpointer function is instantly deleted after it has returnd the value, hence the variable
// a is also removed from stack, thereby the value of a is flushed and replaced by a garbage value
int *returnPointer()
{
    int a = 20;
    int *a_ptr = &a;
    return a_ptr;
}

int main()
{
    int *retruned_ptr = returnPointer();
    std::cout << retruned_ptr << std::endl;
    // if logged the value printed will be a garbage value
    std::cout << *retruned_ptr << std::endl;
    return 0;
}