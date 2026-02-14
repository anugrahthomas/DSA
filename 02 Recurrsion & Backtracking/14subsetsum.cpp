#include <iostream>
#include <vector>
using namespace std;

// output: 6 3 4 1 5 2 3
void backtrack1(int index, int sum, vector<int> &arr, vector<int> &ans) {
    if(index == arr.size()) {
        if(sum != 0) ans.push_back(sum);
        return;
    }

    // include
    backtrack1(index+1, sum + arr[index], arr, ans);

    // exclude
    backtrack1(index+1, sum, arr, ans);
}

// output: 1 3 6 4 2 5 3
void backtrack2(int index, int sum, vector<int> &arr, vector<int> &ans) {
    if(sum!=0) ans.push_back(sum);

    for(int i=index; i<arr.size(); i++){
        sum += arr[i];
        backtrack2(i+1, sum, arr, ans);
        sum -= arr[i];
    }
}

void subsetSum(vector<int> &arr) {
    vector<int> ans;
    int index = 0;
    int sum = 0;

    backtrack1(index, sum, arr, ans);
    // backtrack2(index, sum, arr, ans);
    for(int val: ans) {
        cout << val << " ";
    }
}

int main () {
    vector<int> arr = {1,2,3};
    subsetSum(arr);
    return 0;
}