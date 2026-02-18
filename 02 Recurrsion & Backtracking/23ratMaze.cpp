// simple logic is that we can move D, L, R, U from a point
// leetcode - 980, 79,  include obstacle too
// the maze problem series on lc- 490, 505, 499 but locked
// same intuition in problem like word search

// lc 63,64 look similar but solve using DP

// - You are the rat
// - You start at (0,0)
// - You want to reach (n-1,n-1)
// - You can move only where the cell = 1
// - You can move up / down / left / right
// - You cannot visit a cell twice in the same path
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void backtrack(int row, int col, int n, vector<vector<int>> &maze, vector<vector<bool>> &visited, string path, vector<string> &ans) {
    if(row == n-1 && col == n-1) {
        ans.push_back(path);
        return;
    }

    // down
    if(row+1<n && !visited[row+1][col] && maze[row+1][col] == 1) {
        visited[row][col] = true;
        backtrack(row+1, col, n, maze, visited, path + 'D', ans);
        visited[row][col] = false;
    }

    // left
    if(col-1>=0 && !visited[row][col-1] && maze[row][col-1] == 1){
        visited[row][col] = true;
        backtrack(row, col-1, n, maze, visited, path + 'L', ans);
        visited[row][col] = false;
    }

    // right
    if(col+1<n && !visited[row][col+1] && maze[row][col+1] == 1){
        visited[row][col] = true;
        backtrack(row, col+1, n, maze, visited, path + 'R', ans);
        visited[row][col] = false;
    }

    // up
    if(row-1>=0 && !visited[row-1][col] && maze[row-1][col] == 1){
        visited[row][col] = true;
        backtrack(row-1, col, n, maze, visited, path + 'U', ans);
        visited[row][col] = false;
    }
}

void optimizedBacktrack(int row, int col, int n, vector<vector<int>> &maze, vector<vector<bool>> &visited, string path, vector<string> &ans) { // instead of wrting so many if statement, what if rat move in 8or more direction cannot write so many if
    if(row==n-1 && col==n-1) {
        ans.push_back(path);
        return;
    }
    vector<pair<int, int>> dir = {{1,0}, {0,-1}, {0,1}, {-1,0}}; // D, L, R, U
    string p = "DLRU";
    for(int i=0; i<4; i++) {
        int nextRow = row + dir[i].first;
        int nextCol = col + dir[i].second;
        if(nextRow>=0 && nextRow<n && nextCol>=0 && nextCol<n && !visited[nextRow][nextCol] && maze[nextRow][nextCol]==1) {
            visited[row][col] = true;
            path.push_back(p[i]);
            optimizedBacktrack(nextRow, nextCol, n, maze, visited, path, ans);
            path.pop_back();
            visited[row][col] = false;
        }
    }

}

void ratMaze(vector<vector<int>> &maze) { // time: O(4^(n²)), space: O(n²)
    int n = maze.size();
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    string path = "";
    int row=0, col=0;

    // if(maze[0][0] == 1) backtrack(row, col, n, maze, visited, path, ans);

    if(maze[0][0] == 1) optimizedBacktrack(row, col, n, maze, visited, path, ans);

    for(string str: ans) {
        cout << str << endl;
    }
}

int main() {
    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};
    ratMaze(maze);
    return 0;
}