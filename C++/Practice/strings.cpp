#include <iostream>
#include <string>
using namespace std;

int main(){
    string str1 = "Hello ";
    string str2 = "World";
    string str3 = str1+str2;

    //str1.append(" appended");
    cout << str1[str1.length() - 1];
    return 0;
}