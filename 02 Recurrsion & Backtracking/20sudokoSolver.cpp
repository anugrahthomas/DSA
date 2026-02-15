// 3 rules
// 1. digit 1-9 exactly appears in each row
// 2. digit 1-9 exactly appears in each col
// 3. digit 1-9 exactly appears in each 3x3 matrix

#include<iostream>
#include <vector>
using namespace std;

bool isValid(char ch, int row, int col, vector<vector<char>> &board) {
    for(int i=0; i<9; i++) {
        // checking for row containing same number
        if(board[i][col] == ch) return false;

        // checking col containing same number
        if(board[row][i] == ch) return false;

        // checking 3x3 submatrix containg same number
        if(board[3 * (row/3) + (i/3)][3 * (col/3) + (i%3)] == ch) return false;
    }
    return true;
}

bool solve(vector<vector<char>> &board) {
    for(int row=0; row<board.size(); row++) {
        for(int col=0; col<board[row].size(); col++) {
            if(board[row][col] == '*') {
                for(char ch='1'; ch<='9'; ch++) {
                    if(isValid(ch, row, col, board) == true) {
                        board[row][col] = ch;
                        if(solve(board) == true) {
                            return true;
                        }else {
                            board[row][col] = '*';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void sudokoSolver(vector<vector<char>> &board) { // time: O(9^(n²)) space: O(n²)
    solve(board);
}

int main() {
    vector<vector<char>> board = { {'5','3','*','*','7','*','*','*','*'},
                                   {'6','*','*','1','9','5','*','*','*'},
                                   {'*','9','8','*','*','*','*','6','*'},
                                   {'8','*','*','*','6','*','*','*','3'},
                                   {'4','*','*','8','*','3','*','*','1'},
                                   {'7','*','*','*','2','*','*','*','6'},
                                   {'*','6','*','*','*','*','2','8','*'},
                                   {'*','*','*','4','1','9','*','*','5'},
                                   {'*','*','*','*','8','*','*','7','9'} };

    cout << "INITIAL STATE" << endl;
    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[i].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    sudokoSolver(board);

    cout << "\nFINAL STATE" << endl;
    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[i].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


// 5 3 * * 7 * * * *    ->    5 3 4 6 7 8 9 1 2
// 6 * * 1 9 5 * * *    ->    6 7 2 1 9 5 3 4 8
// * 9 8 * * * * 6 *    ->    1 9 8 3 4 2 5 6 7
// 8 * * * 6 * * * 3    ->    8 5 9 7 6 1 4 2 3
// 4 * * 8 * 3 * * 1    ->    4 2 6 8 5 3 7 9 1
// 7 * * * 2 * * * 6    ->    7 1 3 9 2 4 8 5 6
// * 6 * * * * 2 8 *    ->    9 6 1 5 3 7 2 8 4
// * * * 4 1 9 * * 5    ->    2 8 7 4 1 9 6 3 5
// * * * * 8 * * 7 9    ->    3 4 5 2 8 6 1 7 9

// INITIAL STATE (9x9 containinng 3x3)
// [5 3 *] [* 7 *] [* * *]
// [6 * *] [1 9 5] [* * *]
// [* 9 8] [* * *] [* 6 *]

// [8 * *] [* 6 *] [* * 3]
// [4 * *] [8 * 3] [* * 1]
// [7 * *] [* 2 *] [* * 6]

// [* 6 *] [* * *] [2 8 *]
// [* * *] [4 1 9] [* * 5]
// [* * *] [* 8 *] [* 7 9]

// FINAL STATE (9x9 containinng 3x3)
// [5 3 4] [6 7 8] [9 1 2]
// [6 7 2] [1 9 5] [3 4 8]
// [1 9 8] [3 4 2] [5 6 7]

// [8 5 9] [7 6 1] [4 2 3]
// [4 2 6] [8 5 3] [7 9 1]
// [7 1 3] [9 2 4] [8 5 6]

// [9 6 1] [5 3 7] [2 8 4]
// [2 8 7] [4 1 9] [6 3 5]
// [3 4 5] [2 8 6] [1 7 9]