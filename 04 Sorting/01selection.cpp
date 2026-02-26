// the main concept of this sorting technique is select and sort element one by one
// selecting the minimum and push to front
// check the minimum in array and swap with i (current position)
// initially array: [13, 46, 24, 52, 20, 9]
// step1: 9 46 24 52 20 13 // 9 is sorted
// step2: 9 13 24 52 20 46 // 13 is sorted
// step3: 9 13 20 52 24 46 // 20 is sorted
// step4: 9 13 20 24 52 46 // 24 is sorted
// step5: 9 13 20 24 46 52 // 46 is sorted

#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int arr[], int n){ // O(n^2) non turbulant behavior
    int min;
    for(int i=0; i<=n-2; i++){
        min = i;
        for(int j=i; j<=n-1; j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
}

int main(){
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}