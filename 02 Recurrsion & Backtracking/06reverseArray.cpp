#include <iostream>
using namespace std;



// Array Before: 2 3 4 5 6 
// Array After: 6 5 4 3 2

void swap(int &a, int &b) {
    a = a^b;
    b = a^b;
    a = a^b;
}

void recurrsion(int l, int r, int arr[]) {
    if(l>=r) return;
    swap(arr[l], arr[r]);
    recurrsion(l+1, r-1, arr);
}

int main() {
    int arr[] = {2,3,4,5,6};
    int l = 0;
    int r = sizeof(arr)/sizeof(arr[0]) - 1;
    cout << "Array Before: ";
    for(int i: arr) cout << i << " "; 
    recurrsion(l, r, arr);
    cout << "\nArray After: ";
    for(int i: arr) cout << i << " "; 
}