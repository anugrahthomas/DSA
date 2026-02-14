// leetcode-90
#include <iostream>
#include <vector>
using namespace std;

// array must sorted in this case for handling adjacent duplicates
void backtrack(int index, vector<int> &arr, vector<int> &temp, vector<vector<int>> &ans) {
    ans.push_back(temp);

    for(int i=index; i<arr.size(); i++) {
        if(i>index && arr[i] == arr[i-1]) continue; // ignoring duplictes

        temp.push_back(arr[i]);
        backtrack(i+1, arr, temp, ans);
        temp.pop_back();
    }
}

void subset(vector<int> &arr) {
    vector<vector<int>> ans;
    vector<int> temp; 
    int index = 0; 
    backtrack(index, arr, temp, ans);

    for(int i=0; i<ans.size(); i++) {
        cout << "[ ";
        for(int j=0; j<ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

int main() {
    vector<int> arr = {1,2,2};
    subset(arr);
    return 0;
}