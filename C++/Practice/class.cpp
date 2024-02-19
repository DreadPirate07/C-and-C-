#include <iostream>

class Object
{
private:
    int a;
    int b;

public:
    Object()
    {
        a = 10;
        b = 20;
    }
    Object(int val1, int val2)
    {
        this->a = val1;
        this->a = val2;
    }

    void printAttributes()
    {
        std::cout << a << " " << b << std::endl;
    }
};

int main()
{
    Object obj1;
    Object obj2(50, 100);
    obj1.printAttributes();
    obj2.printAttributes();
    uint16_t t  = 65536;
    std::cout << t << std::endl;
    return 0;
}