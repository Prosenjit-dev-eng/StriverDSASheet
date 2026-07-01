#include<bits/stdc++.h>
using namespace std;
bool isValid(vector<vector<char>>& board, int row, int col, char d){
    for (int i = 0; i < 9; i++)
    {

        if(board[i][col] == d) return false; 
        if(board[row][i] == d) return false; 
            
    }
    int start_i = row/3*3;
    int start_j = col/3*3;

    for (int k = 0; k < 3; k++)
    {
        for (int l = 0; l < 3; l++)
        {
            if (board[start_i+k][start_j+l] == d)
            {
                return false;
            }
            
        }
        
    }
    return true;
    
}
bool solve(vector<vector<char>>& board){
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
            {
                for(char d = '1'; d <= '9'; d++){
                    if (isValid(board,i,j,d))
                    {
                        board[i][j] = d;
                        if(solve(board)) return true;
                        board[i][j] = '.';
                    }
                    
                }
                return false;
            }
            
        }
        
    }
    return true;
    
}
void solveSudoku(vector<vector<char>>& board) {
    solve(board);
}
int main()
{
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    solveSudoku(board);

    return 0;
}