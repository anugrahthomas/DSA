#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high, int &count) {
    vector<int> temp;
    int i=low, j=mid+1;
    while(i<=mid && j<=high) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }else {
            temp.push_back(arr[j]);
            count += (mid-1+1); // all elements greater than in left part will be greater than arr[j]
            j++;
        }
    }
    while(i<=mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=high) {
        temp.push_back(arr[j]);
        j++;
    }
    for(int k=low; k<=high; k++) {
        arr[k] = temp[k-low];
    }
}

void divide(vector<int> &arr, int low, int high, int &count) {
    if(low >= high) return;

    int mid = low + (high - low)/2;
    divide(arr, low, mid, count);
    divide(arr, mid+1, high, count);

    merge(arr, low, mid, high, count);
}

void countInversion(vector<int> &arr) {
    int count = 0;
    int low = 0, high = arr.size() - 1;
    divide(arr, low, high, count);
    cout << "Count of inversion is: " << count << endl;
}

int main() {
    vector<int> arr = {5, 4, 2, 3, 1};
    countInversion(arr);
    return 0;
}