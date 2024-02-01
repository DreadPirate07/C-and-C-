#include <iostream>
#include <cstring>
using namespace std;


int main(){
    int foo =0;
    int source = 4294967296;
    cout << foo << "   foo before" << endl;
    memcpy(&foo,&source,4);
    cout << foo <<" foo after" << endl;
    return 0;
}