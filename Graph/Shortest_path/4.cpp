#include<bits/stdc++.h>
using namespace std;
int n;
int bfs(int r, int c, vector<vector<bool>>& vis, vector<vector<int>>& grid){
    vis[r][c] = true;
    queue<pair<pair<int,int>,int>>q;
    q.push({{r,c},1});// roq,col,distance
    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        if(row == n - 1 && col == n - 1) return dist;
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                int nrow = row+i;
                int ncol = col+j;
                if(nrow < n && nrow >= 0 && ncol < n && ncol >= 0 && !vis[nrow][ncol] && grid[nrow][ncol] == 0){
                    vis[nrow][ncol] = true;
                    q.push({{nrow,ncol},dist+1});
                }
            }
            
        }
        

    }
    return -1;
    
}
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    n = grid.size();
    if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
    vector<vector<bool>> vis(n,vector<bool>(n,false));
    return bfs(0,0,vis,grid);
}
int main()
{
    vector<vector<int>> grid = {{0,1},{1,0}};
    cout<<shortestPathBinaryMatrix(grid)<<endl;
    return 0;
}