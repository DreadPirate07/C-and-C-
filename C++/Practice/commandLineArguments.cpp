// initially compile the file as usual
// pass the arguments in cli as ./outputfile arg1 arg2 arg3

#include <iostream>

int main(int argc, char **argv)
{
    std::cout << argc << std::endl;

    for (int i = 0; i < argc; i++)
    {
        std::cout << argv[i] << std::endl;
    }
}