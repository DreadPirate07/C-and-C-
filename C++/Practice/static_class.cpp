#include <iostream>
using namespace std;
#include<bits/stdc++.h>
class GFG{
    public:
        static int i;
    GFG(){
        
    };

    static void greetMessage(){
        cout << "hello this is a void function" << endl;
    }
};
int GFG::i = 5;
int main(){
    GFG obj1;
    GFG obj2;
    cout << obj1.i << endl;
    cout << obj2.i << endl;
    GFG::greetMessage();
        return 0;

}