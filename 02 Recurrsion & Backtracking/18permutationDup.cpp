// leetcode - 47
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1 1 2 
// 1 2 1 
// 2 1 1 
void backtrack(vector<int> &arr, vector<bool> &used, vector<int> &temp, vector<vector<int>> &ans) {
    if(arr.size() == temp.size()) {
        ans.push_back(temp);
        return;
    }
    for(int i=0; i<arr.size(); i++) {
        if (used[i]) continue;
        if (i > 0 && arr[i] == arr[i-1] && !used[i-1]) continue; // handling dulpicates

        used[i] = true;
        temp.push_back(arr[i]);
        backtrack(arr, used, temp, ans);
        used[i] = false;
        temp.pop_back();
    }
}
void permutationDuplicate(vector<int>& arr) {
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;
    vector<int> temp;
    vector<bool> used(arr.size(), false);

    backtrack(arr, used, temp, ans);

    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<int> arr = {1, 1, 2};
    permutationDuplicate(arr);
    return 0;
}