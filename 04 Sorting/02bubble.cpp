// this approach is opposite to selection sort
// this approach is bubbling up the largest element
// here we take maximum and push to last
// check two adjacent elements and swap
// initially array: [13, 46, 24, 52, 20, 9]
// Step1: 13 24 46 20 09 52 // 52 is sorted
// Step2: 13 24 20 09 46 52 // 46 is sorted
// Step3: 13 20 09 24 46 52 // 24 is sorted
// Step4: 13 09 20 24 46 52 // 20 is sorted
// Step5: 09 13 20 24 46 52 // 13 is sorted

#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int arr[], int n){ // O(n^2) // O(n) using sort variable
    bool sort;
    for(int i=n-1; i>=0; i--){
        sort = false;
        for(int j=0; j<=i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                sort = true;
            }
        }
        if(!sort) break;
    }
}

int main(){
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}