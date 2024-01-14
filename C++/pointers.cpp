#include <iostream>

int main(int argc, char **argv)
{
    int age = 5;

    int *age_ptr;

    age_ptr = &age;

    std::cout << &age_ptr << " "
              << age_ptr << " "
              << *age_ptr << std::endl;

    std::cout << "age and address:"
              << &age << " "
              << age << std::endl;
    // scanf("%d", age_ptr);
    // std::cout << *age_ptr << std::endl;
    int &age_ref = age;
    std::cout << age_ref << std::endl;
    free(age_ptr);
    return 0;
}