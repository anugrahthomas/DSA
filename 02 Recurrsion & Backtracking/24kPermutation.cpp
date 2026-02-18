// bruteforce approach - generate all the permutations and then return the kth one
// which cause a large time complexity of O(n! * n) where n is the number of elements in the permutation
// sorting the permutations will take O(n! * log(n!)) time complexity
#include <iostream>
#include <vector>
using namespace std;

void kPermutation(int n, int k) { // time: O(n^2) space: O(n)
    vector<int> ans;
    vector<int> temp;
    int fact = 1;
    for(int i=1; i<n; i++) {
        temp.push_back(i);
        fact *= i;
    }
    temp.push_back(n);
    k = k-1; // to make it 0 indexed
    while(temp.size() > 0) {
        ans.push_back(temp[k/fact]); // 3/6 = 0, 9/6 = 1, 3/2 = 1
        temp.erase(temp.begin() + k/fact); // remove element
        // if(temp.size() == 0) break;
        k = k % fact; // 3%6 = 3, 9%6 = 3, 3%2 = 1
        fact = fact / temp.size(); // 6/3 = 2, 2/2 = 1
    }

    for(auto i : ans) {
        cout << i << " ";
    }
}

int main() {
    int n = 3;
    int k = 4;

    kPermutation(n, k);
    return 0;
}

// main idea is not to generate all permutations
// eg: n=4, k=9
// n = 4 has total 4! = 24 permutations
// can divide in pair of 4
// 1, {2, 3, 4} - each of 6 permutation - 2, {3,4} - each of 2 permutation - 3, {4} - 1 permutation
// 2, {1, 3, 4} - each of 6 permutation
// 3, {1, 2, 4} - each of 6 permutation
// 4, {1, 2, 3} - each of 6 permutation
// 9th permutation will be in 2, {1, 3, 4} as 9 > 6
// then we can repeat the process for 2, {1, 3, 4} and find the 3rd permutation as 9-6 = 3
