// leetcode - 78
#include <iostream>
#include <vector>
using namespace std;

// output: 
// [ 1 2 3 ]
// [ 1 3 2 ]
// [ 2 1 3 ]
// [ 2 3 1 ]
// [ 3 1 2 ]
// [ 3 2 1 ]

// approch is travel all index one by one and maintain used to check if element is used or not at one level
void backtrack(vector<int> &arr, vector<bool> &used, vector<int> &temp, vector<vector<int>> &ans) { // time: O(n! * n), space: O(n)
    if(arr.size() == temp.size()) {
        ans.push_back(temp);
        return;
    }
    for(int i=0; i<arr.size(); i++) {
        if(used[i] == true) continue; 
        used[i] = true;
        temp.push_back(arr[i]);
        backtrack(arr, used, temp, ans);
        used[i] = false;
        temp.pop_back();
    }
}

void permutation(vector<int> &arr) {
    vector<vector<int>> ans;
    vector<int> temp;
    vector<bool> used(arr.size(), false);

    backtrack(arr, used, temp, ans);

    for(int i=0; i<ans.size(); i++) {
        cout << "[ ";
        for(int j=0; j<ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

int main () {
    vector<int> arr = {1,2,3};
    permutation(arr);
    return 0;
}