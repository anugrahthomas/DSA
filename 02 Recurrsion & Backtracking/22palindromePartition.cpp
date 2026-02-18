#include<iostream>
#include <string>
using namespace std;

bool isPalindrome(int s, int e, string &str) {
    while(s<=e) {
        if(str[s++] != str[e--]) return false;
    }
    return true;
}

void solve(int index, string &str, vector<string> &path, vector<vector<string>> &ans) {
    if(index == str.length()) {
        ans.push_back(path);
        return;
    }

    for(int i=index; i<str.length(); i++) {
        if(isPalindrome(index, i, str)) {
            path.push_back(str.substr(index, i-index+1));
            solve(i+1, str, path, ans);
            path.pop_back();
        }
    }
}

void palindromePartition(string &str){ // time: O(n*2^n) space: O(n)
    vector<vector<string>> ans;
    vector<string> path;
    int partitonPointer = 0;
    solve(partitonPointer, str, path, ans);

    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout << ans[i][j] << ",";
        }
        cout << endl;
    }
}

int main() {
    string str = "aabb";
    palindromePartition(str);
    return 0;
}


//                                                  aabb
//                                  a,abb                                   aa,bb              aab,b          aabb,❌
//             a,a,bb               a,ab,b          a,abb,❌           aa,b,b   aa,bb,✅        aab,b,❌
//      a,a,b,b     a,a,bb,✅       a,ab,b,❌                          aa,b,b,✅
//      a,a,b,b,✅