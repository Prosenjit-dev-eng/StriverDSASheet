#include<bits/stdc++.h>
using namespace std;
int orangesRot(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    queue<pair<pair<int,int>,int>> q;// i,j,time
    for(int i=0;i<m;i++){  
        for(int j=0;j<n;j++){  
            if(mat[i][j]==2) q.push({{i,j},0});  
        }
    }    
    int tm = 0;
    int drow[] = {-1,0,1,0};
    int dcol[] = {0,1,0,-1};

    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int time = q.front().second;
        q.pop();
        tm = max(tm,time);
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && mat[nrow][ncol] == 1 && mat[nrow][ncol] != 2)
            {
                mat[nrow][ncol] = 2;
                q.push({{nrow,ncol},time+1});
            }
            
        }
        
    }
    for(int i=0;i<m;i++){  
        for(int j=0;j<n;j++){  
            if(mat[i][j]==1) return -1;  
        }
    } 
    return tm;
      
}
int main()
{
    return 0;
}