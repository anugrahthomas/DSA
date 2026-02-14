// this is alternate approach to solve permutation, instead of using used array
// here we swap instead of using used array
#include <iostream>
#include <vector>
using namespace std;

// output:
// [ 1 2 3 ]
// [ 1 3 2 ]
// [ 2 1 3 ]
// [ 2 3 1 ]
// [ 3 2 1 ]
// [ 3 1 2 ]
void backtrack(int index, vector<int> &arr, vector<vector<int>> &ans) {
    if(index == arr.size()) {
        ans.push_back(arr);
        return;
    }

    for(int i=index; i<arr.size(); i++) {
        swap(arr[index], arr[i]);
        backtrack(index+1, arr, ans);
        swap(arr[index], arr[i]);
    }
}

void permutation2(vector<int> &arr) { // time: O(n!*n), space:O(n)
    vector<vector<int>> ans;
    int index = 0;

    backtrack(index, arr, ans);
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
    permutation2(arr);
    return 0;
}