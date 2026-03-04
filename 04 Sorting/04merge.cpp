// divide and merge
// initially array: [3, 2, 4, 1, 3]
// first divide: [3, 2, 4] & [1, 3]
// again divide: [3, 2] & [4]       [1,3]
// in the end merge operation
// Recurrsion occurs

// merge function: merge two sorted arrays
// temp array to store merged array
// two pointers left and right
// compare and insert smaller element to temp
// finally copy temp to original array

#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;
    
    while(left<=mid && right<=high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=0; i<temp.size(); i++){
        arr[low + i] = temp[i];
    }
}

void divide(int arr[], int low, int high){
    if(low == high) return;

    int mid = low + (high - low)/2;
  
    divide(arr, low, mid); // O(logn)
    divide(arr, mid+1, high); // O(logn)
    merge(arr, low, mid, high); // O(n)
}

void mergeSort(int arr[], int n){ // time: O(nlog(n)), space: O(n)
    divide(arr, 0, n-1);
}


int main(){
    int arr[] = {2, 1, 2, 4, 1, 5, 6, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, n);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
