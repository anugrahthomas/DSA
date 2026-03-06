#include <iostream>
using namespace std;

// versatile approach works on array, no matter sorted or not
int linearSearch(int arr[], int n, int target) { // time: O(n), space: (1)
    for(int i=0; i<n; i++) {
        if(arr[i] == target) return i;
    }
    return -1;
}

int main() {
    int arr[] = {3,4,1,2,9,7,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 2;

    int res = linearSearch(arr, n, target);

    if(res == -1) {
        cout << target << " element not found" << endl;
    } else {
        cout << target << " element found at " << res << endl;
    }
    return 0;
}