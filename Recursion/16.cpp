#include <bits/stdc++.h>
using namespace std;

// Safety check for placing a queen
bool isSafe(vector<string>& B, int row, int col, int n){
    // Check column above
    for (int i = 0; i < row; i++)
        if (B[i][col] == 'Q')
            return false;

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (B[i][j] == 'Q')
            return false;

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (B[i][j] == 'Q')
            return false;

    return true;
}

// Recursive backtracking function
void nQueens(vector<string>& B, int row, int n, vector<vector<string>>& ans){
    if (row == n){
        ans.push_back(B);
        return;
    }

    for (int col = 0; col < n; col++){
        if (isSafe(B, row, col, n)){
            B[row][col] = 'Q';         // Place queen
            nQueens(B, row + 1, n, ans);
            B[row][col] = '.';         // Backtrack
        }
    }
}

// Main solver function
vector<vector<string>> solveNQueens(int n){
    vector<vector<string>> res;
    vector<string> B(n, string(n, '.')); // Initialize board
    nQueens(B, 0, n, res);
    return res;
}

int main(){
    int n = 4;
    vector<vector<string>> solutions = solveNQueens(n);

    for (auto& board : solutions){
        for (string row : board){
            cout << row << endl;
        }
        cout << "------" << endl;
    }

    return 0;
}
