#include <iostream>
using namespace std;

bool isSorted(int arr[], int n){
    bool result = true;
    for(int i=0; i<n-1; i++){
        if(arr[i] > arr[i+1]){
            result = false;
            break;
        }
    }
    return result;
}


int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);

    if(isSorted(arr, n)){
        cout << "Array is Sorted";
    }else{
        cout << "Array is not Sorted";
    }
}