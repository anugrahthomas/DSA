// this problem has multiple approach to solve this
// 1. power set 
// 2. backtracking

#include <iostream>
#include <vector>
using namespace std;

// []
// ├── [1]
// │   ├── [1,2]
// │   │   └── [1,2,3]
// │   └── [1,3]
// │       └── [1,3,2]
// ├── [2]
// │   ├── [2,1]
// │   └── [2,3]
// └── [3]
//     ├── [3,1]
//     └── [3,2]

// subset
// this is another version of code (for interview)
void backtrack1(int index, vector<int> &arr, vector<int> &temp, vector<vector<int>> & ans) { // time: O(n*2^n), space: O(n*2^n){ans} + O(n){stack}
    ans.push_back(temp); // saving
    for(int i=index; i<arr.size(); i++) {
        temp.push_back(arr[i]); // choose option
        backtrack1(i+1, arr, temp, ans); // try option   // not index+1 because there may be duplication
        temp.pop_back(); // undo 
    }
}


// i=0                       []
//                    /               \
// i=1             [1]                 []
//               /      \           /       \
// i=2       [1,2]     [1]        [2]         []
//           /   \     /   \     /   \       /   \
// i=3  [1,2,3] [1,2] [1,3] [1] [2,3] [2]   [3]  [] // saving at last

// this is more beginer friendly easy to understand how recurrsion works
void backtrack2(int index, vector<int> &arr, vector<int> &temp, vector<vector<int>> & ans) { // time: O(n*2^n), space: O(n * 2^n){ans} + O(n){stack}
    if(index == arr.size()) { // base condition if index==size save it
        ans.push_back(temp);
        return;
    }

    // include
    temp.push_back(arr[index]);
    backtrack2(index+1, arr, temp, ans);
    
    //exclude
    temp.pop_back();
    backtrack2(index+1, arr, temp, ans);
}

void subsequence(vector<int> &arr) {
    vector<int> temp;
    vector<vector<int>> ans;
    int index = 0;
    // backtrack1(index, arr, temp, ans);
    backtrack2(index, arr, temp, ans);

    for(int i=0; i<ans.size(); i++) {
        cout << "[ ";
        for(int j=0; j<ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

// recurrion approach 
// - i=0, include, exclude
// - i=1, include, exclude
// - i=2, include, exclude
// - i=3, save and return 

int main() {
    vector<int> arr = {1,2,3};
    subsequence(arr);
    return 0;
}

// Error while solving, index+1, in bracktack function,