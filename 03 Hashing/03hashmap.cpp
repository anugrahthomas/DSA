#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int, int> mpp; // orderedMap, sorted in nature, 
    int arr[] = {1,2,1,2,2,93,32,1,32,9};
    int n = sizeof(arr) / sizeof(arr[0]);
    for(int i=0; i<n; i++){
        mpp[arr[i]]++; // mpp[key] this gives value just like array
    }
    for(auto i : mpp){
        cout << "key: " << i.first << " -> " << "value: " << i.second << endl;
    }
}