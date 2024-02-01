#include <bits/stdc++.h>
using namespace std;

bool isPresent(int n, int ArrInput[], int size){
    for (int i = 0 ; i < size ; i++){
        if (ArrInput[i] == n) return true;
    }
    return false;
}

void createUniqueArr (int arr1[],int arr2[], int arr1Size){
    int uniqueArrcount = 0;
    for (int i = 0 ; i < arr1Size ; i++){
        if (!isPresent(arr1[i],arr2,((arr1Size-1)/2)+1)){
            arr2[uniqueArrcount] = arr1[i];
            uniqueArrcount++;
        }
    }
}

int getCount(int arr[], int ele, int size) {
    int count = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] == ele) count++;
    }
    return count;
}

int main(){
    int arr[] = {2,2,5,4,4,5,6,2};
    int arrSize = (sizeof(arr)/sizeof(arr[0]));
    int uniqueArr[((arrSize-1)/2)+1];
    createUniqueArr(arr,uniqueArr,arrSize);
    for (auto it:uniqueArr){
        int count = getCount(arr, it, arrSize);
        if(count == 1) cout << it << endl;
    }
    return 0;
}
