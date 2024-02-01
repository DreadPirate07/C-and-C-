#include<iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> a;
    a.resize(2);
    a[3] = 10;
    cout << a.size() << endl;
    return 0;

}