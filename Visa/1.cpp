#include<bits/stdc++.h>
using namespace std;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};
int m,n;
void dfs(int i, int j, vector<vector<bool>>&vis, vector<vector<char>>& grid){
    vis[i][j] = true;
    for (int k = -1; k <= 1; k++)
    {
        for (int l = -1; l <= 1; l++)
        {
            int row = i+k;
            int col = j + l;
            if(row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == 'L' && !vis[row][col]) dfs(row,col,vis,grid);
        }
        

    }
    
     
}
int countIslands(vector<vector<char>>& grid) {
    m = grid.size(), n = grid[0].size();
    vector<vector<bool>>vis(m,vector<bool>(n,false));
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 'L' && !vis[i][j])
            {
                cnt++;
                dfs(i,j,vis,grid);
            }
            
        }
        
    }
    return cnt;
            
}
int main()
{
    vector<vector<char>>grid {{'L', 'L', 'W', 'W', 'W'},
                            {'W', 'L', 'W', 'W', 'L'},
                           {'L', 'W', 'W', 'L', 'L'},
                          {'W', 'W', 'W', 'W', 'W'},
                         {'L', 'W', 'L', 'L', 'W'}};
    cout<<countIslands(grid)<<endl;
    return 0;
}