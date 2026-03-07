#include <iostream>
using namespace std;

// first thing array has to be sorted while using binary search
int binarySearchI(int arr[], int n, int target) { // time: O(logn), space: O(1)
    int low = 0, high = n-1;
    while(low <= high) {
        int mid = low+(high-low)/2;
        if(arr[mid] == target) {
            return mid;
        }else if(arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int binarySearchR(int arr[], int low, int high, int target) { // time: O(logn), space: O(logn)
    if(low > high) return -1;

    int mid = low + (high - low)/2;

    if(arr[mid] == target) {
        return mid;
    }else if(arr[mid] > target) {
        return binarySearchR(arr, low, mid-1, target);
    }
    return binarySearchR(arr, mid+1, high, target);
}

int main() {
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 3;

    int low = 0, high = n-1;
    // int res = binarySearchR(arr, low, high, target);

    int res = binarySearchI(arr, n, target);
    if(res == -1) {
        cout << target << " element not found" << endl;
    } else {
        cout << target << " element found at " << res << endl;
    }
    return 0;
}