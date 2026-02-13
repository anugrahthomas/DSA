// this is leetcode 39
// main approach is pick and not pick the element
// check sum == target // save
// purning sum>target

// this is basic approach to solve leetcode 39, 40, 216, *(377), 77, 

#include <iostream>
using namespace std;

// this is a combination, using index to prevent duplication, only move forword while trying that index also
// solution 1, for loop running from based on index to maintain order (for interview)
void backtrack1(int index, int target, int &sum, vector<int> &arr, vector<int> &temp, vector<vector<int>> &ans) { // O(lenOftemp*2^target), space: O(exponential)
    if(sum > target) return; // pruning
    if(sum == target) {
        ans.push_back(temp); // saving
        return;
    }

    for(int i=index; i<arr.size(); i++) {
        // include
        sum += arr[i];
        temp.push_back(arr[i]);

        // futher solving or evaluate new option
        backtrack1(i, target, sum, arr, temp, ans);

        // exclude
        sum -= arr[i];
        temp.pop_back();
    }
}

// output: 
// [ 2 2 2 2 ]
// [ 2 3 3 ]
// [ 2 6 ] 

// solution 2 pick and not pick, classic recurrsion
void backtrack2(int index, int target, int &sum, vector<int> &arr, vector<int> &temp, vector<vector<int>> &ans) { // O(lenOftemp*2^target), space: O(exponential)
    if (sum == target) {
        ans.push_back(temp);
        return;
    }
    if (sum > target || index == arr.size()) {
        return;
    }

    // pick
    sum += arr[index];
    temp.push_back(arr[index]);
    backtrack2(index, target, sum, arr, temp, ans);

    // not pick
    sum -= arr[index];
    temp.pop_back();
    backtrack2(index+1, target, sum, arr, temp, ans);
}

void combinationSum(vector<int> &arr, int target) { // time: O(exponential), space: O(exponential)
    vector<vector<int>> ans;
    vector<int> temp;
    int index = 0;
    int sum = 0;

    backtrack1(index, target, sum, arr, temp, ans);
    // backtrack2(index, target, sum, arr, temp, ans);

    for(int i=0; i<ans.size(); i++) {
        cout << "[ ";
        for(int j=0; j<ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

int main() {
    vector<int> arr = {2,3,6};
    int target = 8;

    combinationSum(arr, target);
    return 0;
}

// loop based takes less recurrsion calls, tree is narrower, better at scale, better control, 
// subset style takes more recurrsion calls, tree is wider, worst at scale(stack overhead), bad control
