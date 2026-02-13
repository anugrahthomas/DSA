#include <iostream>
#include <vector>
using namespace std;

// it is a kindof permutaion for each option
void backtrack(int index, vector<int> &arr, vector<int> &temp, int &sum, vector<vector<int>> &ans, int k) { // time: O(n*2^n), space: O(n*2^n)
    if(index == arr.size()) {
        if(sum == k) {
            ans.push_back(temp);
        }
        return;
    }

    // include
    sum += arr[index];
    temp.push_back(arr[index]);
    if (sum <= k) { // pruning condition, for reducing unnecessary calls, for +ve only
        backtrack(index+1, arr, temp, sum, ans, k);
    }

    // exclude
    sum -= arr[index];
    temp.pop_back();
    backtrack(index+1, arr, temp, sum, ans, k);
}

void subsequencekSum(vector<int> &arr) {
    vector<vector<int>> ans;
    vector<int> temp;
    int index = 0;
    int sum = 0;
    int k = 3;

    backtrack(index, arr, temp, sum, ans, k);
    for(int i=0; i<ans.size(); i++) {
        cout << "[ ";
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " "; 
        }
        cout << "]" << endl;
    }
}

int main() {
    vector<int> arr = {1,2,3};

    subsequencekSum(arr);
    return 0;
}