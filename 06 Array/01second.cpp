// there are many approaches like bruteforce, better, optimal

// solutions 
// 1. sorting array and smallest is at 0 and 1 index O(nlog n)
// 2. 2 variables i -> smallest, j -> second smallest
#include <iostream>
using namespace std;


int ssmall(int arr[], int n){
    int smallest = arr[0];
    int ssmallest = INT_MAX;
    for(int i=1; i<n; i++){
        if(smallest > arr[i]){
            ssmallest = smallest;
            smallest = arr[i];
        }else if(smallest != arr[i] && ssmallest > arr[i]){
            ssmallest = arr[i];
        }
    }
    return ssmallest;
}

int llarge(int arr[], int n){
    int largest = arr[0];
    int slargest = -1;
    for(int i=1; i<n; i++){
        if(largest < arr[i]){
            slargest = largest;
            largest = arr[i];
        }else if(largest < arr[i] && slargest < arr[i]){
            slargest = arr[i];
        }
    }
    return slargest;
}

int main(){
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    int secondSmallest = ssmall(arr, n);
    int secondLargest = llarge(arr, n);

    cout << "Second Smallest: " << secondSmallest << endl;
    cout << "Second Largest: " << secondLargest << endl;
}