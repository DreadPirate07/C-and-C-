#include <bits/stdc++.h> 
#include <vector>
using namespace std;


vector<int> rotateArray(vector<int>& arr, int n) {
    // Write your code here.
    int i,j = 0;
    for (i = 0 ; i < n-1 ; i++){
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
    }
    return arr;
}

int main(){
    vector<int> arr = {3,1,6,5,10,7,6,6,1,7};
    vector<int> newarr = rotateArray(arr,10);
    cout << arr[0] << endl;
    return 0;
}