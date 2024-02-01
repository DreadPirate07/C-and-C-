#include <iostream>
using namespace std;

void sizeofFunction(int arr[]){
    cout << sizeof(arr) << endl;
}

int main(){
    int arr[] = {1,2,3,4,5};
    sizeofFunction(arr);
}