#include <iostream>

int main()
{
    // auto func = [](int a)
    // {
    //     std::cout << "Hello World "<< a << std::endl;
    // };

    // func(5);
    auto lamAdd = [](int a, int b)
    {
        return a + b;
    };
    int addLambda = lamAdd(3, 5);
    std::cout << addLambda << std::endl;
    return 0;
}