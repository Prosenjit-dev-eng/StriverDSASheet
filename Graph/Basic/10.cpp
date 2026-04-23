#include<bits/stdc++.h>
using namespace std;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            mat[r][c] = dist;
            for(int i = 0; i < 4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol},dist + 1});
                }
            }
        }
        return mat;

    }
int main()
{
    // mat = [[0,0,0],[0,1,0],[1,1,1]]
    vector<vector<int>>mat = {{0,0,0},{0,1,0},{1,1,1}};
    vector<vector<int>>ans = updateMatrix(mat);
    for(auto it : ans){
        for(auto jt : it){
            cout<<jt<<" ";
        }
        cout<<endl;
    }
    return 0;
}