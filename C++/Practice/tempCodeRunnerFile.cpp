int main(int argc, char **argv)
{
    std::cout << argc << std::endl;

    for (int i = 0; i < 5; i++)
    {
        std::cout << argv[i] << std::endl;
    }
}