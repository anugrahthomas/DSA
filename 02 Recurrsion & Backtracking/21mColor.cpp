#include <iostream>
using namespace std;

bool isSafe(int node, int color, vector<int> &colors, vector<vector<int>> &edges) {
    for(int i: edges[node]) {
        if(colors[i] == color) return false;
    }
    return true;
}

bool solve(int node, int m, int n, vector<int> &colors, vector<vector<int>> &edges) {
    if(node == n) return true;

    for(int color=1; color<=m; color++) {
        if(isSafe(node, color, colors, edges)) {
            colors[node] = color;
            if(solve(node+1, m, n, colors, edges)) return true;
            colors[node] = 0;
        }
    }
    return false;
}

bool mGraphColor(int &vertices, vector<vector<int>> &edges, int m) { // time: O(n^m), space: O(n)
    int node = 0;
    vector<int> colors(vertices,0);
    return solve(node, m, vertices, colors, edges);
}

int main() {
    vector<vector<int>> edges = { // adjacency list
        {1, 2, 3},  // neighbors of 0
        {0, 3},     // neighbors of 1
        {0, 3},     // neighbors of 2
        {0, 1, 2}   // neighbors of 3
    };
    int vertices = 4;
    int m = 2;

    if(mGraphColor(vertices, edges, m)) {
        cout << "Can place m = "<< m << " colors" << endl;
    }else {
        cout << "Can't place m = " << m << " colors" << endl;
    }
    return 0;
}