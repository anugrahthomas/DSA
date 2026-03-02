// diving the array into 2 parts 1.sorted 2.unsorted
// take element one by one and maintain a sorted array
// we select element one by one and put at their correct position
// initial element is sorted
// initially array: [13, 46, 24, 52, 20, 9]
// Step0: [13] 46 24 52 20 09
// Step1: [13 46] 24 52 20 09 // 46 is sorted
// Step2: [13 24 46] 52 20 09 // 24 is sorted
// Step3: [13 24 46 52] 20 09 // 52 is sorted
// Step4: [13 20 24 46 52] 09 // 20 is sorted
// Step5: [09 13 20 24 46 52] // 09 is sorted

#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(int arr[], int n){ // O(n^2)
    int j;
    for(int i=0; i<n; i++){
        j=i;
        while(j>0 && arr[j-1] > arr[j]){
            swap(arr[j], arr[j-1]);
            j--;
        }
        print(arr, n);
    }
}

int main(){
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}