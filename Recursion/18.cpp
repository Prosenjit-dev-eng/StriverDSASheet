#include <bits/stdc++.h>
using namespace std;

vector<string> res; // global result list

void ratInMaze(int i, int j, vector<vector<int>>& maze, string &path, int n) {
    // check boundary and block
    if (i < 0 || j < 0 || i >= n || j >= n || maze[i][j] == 0)
        return;

    // reached destination
    if (i == n - 1 && j == n - 1) {
        res.push_back(path);
        return;
    }

    maze[i][j] = 0; // To mark the cell, where I don't want to go-> Do 

    // Left
    path.push_back('L');
    ratInMaze(i, j - 1, maze, path, n);
    path.pop_back();

    // Right
    path.push_back('R');
    ratInMaze(i, j + 1, maze, path, n);
    path.pop_back();

    // Down
    path.push_back('D');
    ratInMaze(i + 1, j, maze, path, n);
    path.pop_back();

    // Up
    path.push_back('U');
    ratInMaze(i - 1, j, maze, path, n);
    path.pop_back();

    maze[i][j] = 1; // bcz we want to check the other paths also-> undo
}

vector<string> findPath(vector<vector<int>>& maze, int n) {
    string path = "";
    ratInMaze(0, 0, maze, path, n);
    return res;
}

// In this type of questions, where we have many options
// If it's a 2-D array = n^2
// Then the no of options are m => T.C. = o(m^(n^2))

// Here The rat has 3 options , it does not go where it was
// So T.C. = o(3^(n^2))

// Here the worst case is all cell == 1
// So space complexity is O(n^2) bcz we've to traverse all the cells(Always remember it's the stack space of memory)
// It is gain by drawing the recursion tree

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    vector<string> paths = findPath(maze, 4);

    if (paths.empty())
        cout << "No path found!" << endl;
    else {
        cout << "Possible paths:" << endl;
        for (auto S : paths)
            cout << S << endl;
    }

    return 0;
}
