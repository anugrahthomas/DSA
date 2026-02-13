#include <iostream>
#include <vector>
using namespace std;

int recurrsion(vector<int> &arr, int target, int l, int h) { // time: O(logn), space: O(log n)
    if(l>h) return -1;
    int m = l+(h-l)/2;
    if(arr[m] == target) return m;
    if(arr[m] > target) return recurrsion(arr, target, l, m-1);
    return recurrsion(arr, target, m+1, h);
}

int binarySearch(vector<int> &arr, int target) {
    int l = 0, h = arr.size()-1;
    return recurrsion(arr, target, l, h);
} 

int main() {
    vector<int> arr = {1,2,3,4,5,6};
    int target = 5;

    int res = binarySearch(arr, target);
    cout << "res: " << res << endl;

    return 0;
}