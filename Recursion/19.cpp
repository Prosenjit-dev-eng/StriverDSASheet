#include<bits/stdc++.h>
using namespace std;
    int m, n;
    vector<vector<int>> dirs{{1,0},{-1,0},{0,1},{0,-1}};
    bool find(vector<vector<char>>& board, int i, int j, int idx, string word){
        if(idx == word.length()) return true;
        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[idx] || board[i][j] == '$'){
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '$';// visited
        for(auto &d : dirs){
            int new_i = i+d[0];
            int new_j = j+d[1];
            if(find(board, new_i, new_j, idx+1, word)) return true;
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0] && find(board,i,j,0,word)){
                    return true;
                }
            }   
        }
        return false;
    }
int main()
{
    m = 3, n = 4;
    vector<vector<char>> board{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    cout << exist(board, word) << endl;
    return 0;
}