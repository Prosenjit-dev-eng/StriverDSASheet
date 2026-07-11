#include<bits/stdc++.h>
using namespace std;
int n;
int m;
void dfs(int row, int col, vector<vector<bool>>&vis, vector<vector<char>>& grid){
    vis[row][col] = true;
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    for (int k = 0; k < 4; k++) {
        int nrow = row + dr[k];
        int ncol = col + dc[k];

        if (nrow >= 0 && nrow < m &&
            ncol >= 0 && ncol < n &&
            grid[nrow][ncol] == '1' &&
            !vis[nrow][ncol]) {

            dfs(nrow, ncol, vis, grid);
        }
    }
}
int numIslands(vector<vector<char>>& grid) {
    m = grid.size(), n = grid[0].size();
    vector<vector<bool>>vis(m,vector<bool>(n,false));
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(!vis[i][j] && grid[i][j] == '1'){
                cnt++;
                dfs(i,j,vis,grid);
            }
        }
        
    }
    return cnt;
    
}
// BFS
/*void bfs(int row, int col, vector<vector<bool>>&vis, vector<vector<char>>& grid){
    vis[row][col] = true;
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    queue<pair<int,int>>q;
    q.push({row,col});
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
    for (int k = 0; k < 4; k++) {
        int nrow = row + dr[k];
        int ncol = col + dc[k];

        if (nrow >= 0 && nrow < m &&
            ncol >= 0 && ncol < n &&
            grid[nrow][ncol] == '1' &&
            !vis[nrow][ncol]) {
            vis[nrow][ncol] = true;
            q.push({nrow,ncol});
        }
    }
    }
}
int numIslands(vector<vector<char>>& grid) {
    m = grid.size(), n = grid[0].size();
    vector<vector<bool>>vis(m,vector<bool>(n,false));
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(!vis[i][j] && grid[i][j] == '1'){
                cnt++;
                bfs(i,j,vis,grid);
            }
        }
        
    }
    return cnt;
    
}*/

int main()
{
    vector<vector<char>> grid = {

        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'},

    };
    cout<<numIslands(grid)<<endl;

    return 0;
}