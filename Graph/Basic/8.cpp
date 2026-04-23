#include<bits/stdc++.h>
using namespace std;

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //{{r,c},t}
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
            }
        }

        int tm = 0;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm,t); 
            q.pop();
            for(int i = 0; i < 4; i++){
                int nrow = r + drow[i];// neighbouring row
                int ncol = c + dcol[i];// neighbouring col
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1){
                    q.push({{nrow,ncol}, t+1});
                    vis[nrow][ncol] = 2;
                }
            }
        }
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && vis[i][j] != 2){
                    return -1;
                }
            }
        }
        return tm;
        
    }

int main()
{
    // grid = [[2,1,1],[1,1,0],[0,1,1]]
    vector<vector<int>>grid = {{2,1,1},{1,1,0},{0,1,1}};
    cout<<orangesRotting(grid)<<endl;
    return 0;
}