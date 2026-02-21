#include <iostream>
using namespace std;

int main() {
    int arr[] = {1,2,3,2,1,2,3,2,2,4};
    int hashTable[5] = {0};
    int arrLength = sizeof(arr) / sizeof(arr[0]);
    for(int i=0; i<arrLength; i++){
        hashTable[arr[i]]++;
    }
    int l = sizeof(hashTable) / sizeof(arr[0]);
    for(int i=0; i<l; i++){
        cout << "key: " << i << " value: "<< hashTable[i] << endl;
    }

}