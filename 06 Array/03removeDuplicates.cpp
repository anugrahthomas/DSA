#include <iostream>
using namespace std;

int removeDuplicates(int arr[], int n){
    int i = 0;
    for(int j=0; j<n; j++){
        if(arr[i] != arr[j]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    return i+1;
}


int main(){
    int arr[] = {1,1,2,2,2,3,3,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    for(int i : arr){
        cout << i << " ";
    }
    cout << endl;
    int r = removeDuplicates(arr, n);
    for(int i=0; i<r; i++){
        cout << arr[i] << " ";
    }

}