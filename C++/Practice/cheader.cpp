#include <iostream>
#include <cstdio> // using c library in cpp
using namespace std;

int main()
{
    int x;
    printf("Hello world in cpp");
    scanf("%d", &x);
    cout << x << endl;
    for (int i = 0; i < 5; ++i)
    {
        cout << i << " ";
    }
    return 0;
}