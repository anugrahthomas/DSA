// 3 rules
// 1. every row has a queen
// 2. every col has a queen
// 4. no two queens are in attacking position

// safety function:
// - checking diagonal 
//     - for upper diagonal row--, col--; bcz we have to check only for prev, bcz it is already placed, next is not placed yet
//     - for lower diagonal row++, col--; bcz it moving down and previous
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// for safety we have to check only previous, already placed queens
// ↖
// ←
// ↙
bool safety(int row, int col, int n, vector<string> &board) {
    int r = row; // optimize r = row-1 (avoid unnecessary check for curr position)
    int c = col; // optimize c = col-1 (avoid unnecessary check for curr position)
    // checking upper diagonal (↖)
    // eg: row=2, col=2 previous diagonal is [1, 1]
    while(r>=0 && c>=0) {
        if(board[r][c] == 'Q') return false;
        r--;
        c--;
    }

    c = col; // optimize c = col-1 (avoid unnecessary check for curr position)
    // previous in the row check (←)
    // changing col and fixing row [0][1], [0][2]...
    while(c>=0) {
        if(board[row][c] == 'Q') return false;
        c--;
    }

    r = row; // optimize r = row+1 (avoid unnecessary check for curr position)
    c = col; // optimize c = col-1 (avoid unnecessary check for curr position)
    // checking lower diagonal (↙)
    // eg: row=2, col=2 previous diagonal is [3, 0]
    while(r<n && c>=0) {
        if(board[r][c] == 'Q') return false;
        r++;
        c--;
    }
    return true;
}

// board[row] is string, board[row][col] is character
void backtrack(int col, int n, vector<string> &board, vector<vector<string>> &ans) {
    if(col == n) {
        ans.push_back(board);
        return;
    }

    for(int row=0; row<n; row++) {
        if(safety(row, col, n, board) == false) continue;
        board[row][col] = 'Q';
        backtrack(col+1, n, board, ans);
        board[row][col] = '*';
    }
}

void optimizedBacktrack(int col, int n, vector<string> &board, vector<int> &left, vector<int> &upper, vector<int> &lower, vector<vector<string>> &ans) {
    if(col == n) {
        ans.push_back(board);
        return;
    }

    for(int row=0; row<n; row++) {
        if(left[row] == 0 && upper[(n-1+col-row)] == 0 && lower[row+col] == 0) { // means exist
            board[row][col] = 'Q';
            left[row] = 1;
            lower[row+col] = 1;
            upper[(n-1+col-row)] = 1;
            optimizedBacktrack(col+1, n, board, left, upper, lower, ans);
            board[row][col] = '*';
            left[row] = 0;
            lower[row+col] = 0;
            upper[(n-1+col-row)] = 0;
        }
    }
}

//  physical view starting borad: ["****", "****", "****", "****"] // NxN
// logical view starting board: * * * *
//                              * * * *
//                              * * * *
//                              * * * *
void nQueen(int n) { // time: O(n! * n), space: O(n^2)
    vector<vector<string>> ans;
    vector<string> board(n); // rows
    string s(n, '*'); // n sized string for board
    int col = 0;

    for(int i=0; i<s.length(); i++) {
        board[i] = s; // putiing string in array become N x N board
    }

    // backtrack(col, n, board, ans);

    vector<int> left(n, 0);
    vector<int> upper(2*n-1, 0);
    vector<int> lower(2*n-1, 0);
    optimizedBacktrack(col, n, board, left, upper, lower, ans);

    for(int i=0; i<ans.size(); i++) {
        cout << "Solution" << i+1 << endl;
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                cout << ans[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    int n = 4;
    nQueen(n);

    return 0;
}

// how it is working 

// starting 
// solve(col=0) -> initailly                       root
//                                                * * * *
//                                                * * * *
//                                                * * * *
//                                                * * * *
// col=1              b1                  b2                    b3                     b4
//                 Q * * *             * * * *               * * * *                * * * *
//                 * * * *             Q * * *               * * * *                * * * *
//                 * * * *             * * * *               Q * * *                * * * *
//                 * * * *             * * * *               * * * *                Q * * *
// col=1, b1                                       b1
//                                               Q * * *
//                                               * * * *
//                                               * * * *
//                                               * * * *
// col=2, b1        c1(❌)              c2(❌)                c3(✅)                 c4(✅)
//                 Q Q * *             Q * * *              Q * * *                Q * * *
//                 * * * *             * Q * *              * * * *                * * * *
//                 * * * *             * * * *              * Q * *                * * * *
//                 * * * *             * * * *              * * * *                * Q * *
// col=2, b1->c3                                    c3
//                                               Q * * *
//                                               * * * *
//                                               * Q * *
//                                               * * * *
// col=3 b1->c3     d1(❌)              d2(❌)                d3(❌)                 d4(❌)
//                 Q * Q *             Q * * *              Q * * *                Q * * *
//                 * * * *             * * Q *              * * * *                * * * *
//                 * Q * *             * Q * *              * Q Q *                * Q * *
//                 * * * *             * * * *              * * * *                * * Q *

// col=2, b1->c4                                    c4
//                                               Q * * *
//                                               * * * *
//                                               * * * *
//                                               * Q * *
// col=3 b1->c4     d1(❌)              d2(❌)                d3(❌)                 d4(❌)
//                 Q * Q *             Q * * *              Q * * *                Q * * *
//                 * * * *             * * Q *              * * * *                * * * *
//                 * * * *             * * * *              * * Q *                * * * *
//                 * Q * *             * Q * *              * Q * *                * Q Q *


// col=1, b2                                       b2
//                                               * * * *
//                                               Q * * *
//                                               * * * *
//                                               * * * *
// col=2, b2        c1(❌)              c2(❌)                c3(❌)                 c4(✅)
//                 * Q * *             * * * *              * * * *                * * * *
//                 Q * * *             Q Q * *              Q * * *                Q * * *
//                 * * * *             * * * *              * Q * *                * * * *
//                 * * * *             * * * *              * * * *                * Q * *
// col=2, b2->c4                                   c4
//                                               * * * *
//                                               Q * * *
//                                               * * * *
//                                               * Q * *
// col=3, b2->c4    d1(✅)              d2(❌)                d3(❌)                 d4(❌)
//                 * * Q *             * * * *              * * * *                * * * *
//                 Q * * *             Q * Q *              Q * * *                Q * * *
//                 * * * *             * * * *              * * Q *                * * * *
//                 * Q * *             * Q * *              * Q * *                * Q Q *
// col=3, b2->c4->d1                                d1
//                                               * * Q *
//                                               Q * * *
//                                               * * * *
//                                               * Q * *
//col=4,b2->c4->d1  e1(❌)              e2(❌)                e3(✅)                 e4(❌)
//                 * * Q Q             * * Q *              * * Q *                * * Q *
//                 Q * * *             Q * * Q              Q * * *                Q * * *
//                 * * * *             * * * *              * * * Q                * * * *
//                 * Q * *             * Q * *              * Q * *                * Q * Q

// path-> root->b2->c4->d1->e3 is solution

// Tree View of N-Queen
// row=0, root
// Start
// ├── (0,0)
// ├── (0,1)
// ├── (0,2)
// └── (0,3)

// row=1, branch1
// (0,0)                                           
// ├── (1,0) ❌ column                  
// ├── (1,1) ❌ diagonal                    
// ├── (1,2) ✅                 
// └── (1,3) ✅    

// row=2, branch1
// (0,0)
//  └── (1,2)
//      ├── (2,0) ❌ column
//      ├── (2,1) ❌ diagonal
//      ├── (2,2) ❌ column
//      └── (2,3) ❌ diagonal

// row=2, branch1
// (0,0)
//  └── (1,3)
//      ├── (2,0) ❌ column
//      ├── (2,1) ✅
//      ├── (2,2) ❌ diagonal
//      └── (2,3) ❌ column

// row=3, branch1
// (0,0)
//  └── (1,3)
//      └── (2,1)
//          ├── (3,0) ❌ column
//          ├── (3,1) ❌ column
//          ├── (3,2) ❌ diagonal
//          └── (3,3) ❌ diagonal

// row=1, branch2
// (0,1)
// ├── (1,0) ❌ diagonal
// ├── (1,1) ❌ column
// ├── (1,2) ❌ diagonal
// └── (1,3) ✅

// row=2, branch2
// (0,1)
//  └── (1,3)
//      ├── (2,0) ✅
//      ├── (2,1) ❌ column
//      ├── (2,2) ❌ diagonal
//      └── (2,3) ❌ column

// row=3, branch2
// (0,1)
//  └── (1,3)
//      └── (2,0)
//          ├── (3,0) ❌ column
//          ├── (3,1) ❌ column
//          ├── (3,2) ✅ 🎯
//          └── (3,3) ❌ column

// we got solution1, after this
// * Q * *
// * * * Q
// Q * * *
// * * Q *

// row=1, branch3
// (0,2)
// ├── (1,0) ✅
// ├── (1,1) ❌ diagonal
// ├── (1,2) ❌ column
// └── (1,3) ❌ diagonal

// row=2, branch3
// (0,2)
//  └── (1,0)
//      ├── (2,0) ❌ column
//      ├── (2,1) ❌ diagonal
//      ├── (2,2) ❌ column
//      └── (2,3) ✅

// row=3, branch3
// (0,2)
//  └── (1,0)
//      └── (2,3)
//          ├── (3,0) ❌ column
//          ├── (3,1) ✅ 🎯
//          ├── (3,2) ❌ column
//          └── (3,3) ❌ column

// we got solution2 after this
// * * Q *
// Q * * *
// * * * Q
// * Q * *

// row=1, branch4
// (0,3)
// ├── (1,0) ✅
// ├── (1,1) ✅
// ├── (1,2) ❌ diagonal
// └── (1,3) ❌ column

// row=2, branch4
// (0,3)
//  └── (1,0)
//      ├── (2,0) ❌ column
//      ├── (2,1) ❌ diagonal
//      ├── (2,2) ✅
//      └── (2,3) ❌ column

// row=3, branch4
// (0,3)
//  └── (1,0)
//      └── (2,2)
//          ├── (3,0) ❌ column
//          ├── (3,1) ❌ diagonal
//          ├── (3,2) ❌ column
//          └── (3,3) ❌ column

// row=2, branch4
// (0,3)
//  └── (1,1)
//      ├── (2,0) ❌ diagonal
//      ├── (2,1) ❌ column
//      ├── (2,2) ❌ diagonal
//      └── (2,3) ❌ column

// No furhter solution
// Total leaf paths explored: many (pruned early)
// Total valid solutions: 2
// Tree depth: 4