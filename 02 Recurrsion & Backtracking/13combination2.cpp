// leetcode-40

#include <iostream>
#include <vector>
using namespace std;

// output: 
// [ 1 1 6 ]
// [ 1 2 5 ]
// [ 1 7 ]
// [ 2 6 ]
void backtrack(int index, int target,int &sum, vector<int> &arr, vector<int> &temp, vector<vector<int>> &ans) {
    if(sum == target) {
        ans.push_back(temp);
        return;
    }
    if(sum > target || index == arr.size()) return;

    for(int i=index; i<arr.size(); i++) {
        if(i>index && arr[i] == arr[i-1]) continue; // ignoring duplicates

        sum += arr[i];
        temp.push_back(arr[i]);
        backtrack(i+1, target, sum, arr, temp, ans);
        sum -= arr[i];
        temp.pop_back();
    }
}

void combination2(vector<int> &arr, int target) {
    vector<int> temp;
    vector<vector<int>> ans;
    int index = 0; // maintaing order
    int sum = 0;
    backtrack(index, target, sum, arr, temp, ans);

    for(int i=0; i<ans.size(); i++) {
        cout << "[ ";
        for(int j=0; j<ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "]" << endl;
    }
}
int main() {
    vector<int> arr = {10,1,2,7,6,1,5};
    int target = 8;
    sort(arr.begin(), arr.end()); // must be sorted
    combination2(arr, target);
}