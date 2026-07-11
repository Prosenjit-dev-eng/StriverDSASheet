#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>> P;
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
int minimumEffortPath(vector<vector<int>>& heights) {
    priority_queue<P, vector<P>, greater<P>> pq;// Difference,row,col
    int m = heights.size(), n = heights[0].size();
    vector<vector<int>> dist(m,vector<int>(n,1e9));
    dist[0][0] = 0;
    pq.push({0,{0,0}});
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int diff =it.first;
        int row = it.second.first;
        int col = it.second.second;
        if(row == m - 1 && col == n - 1) return diff;
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if(nrow < m && ncol < n && nrow >= 0 && ncol >= 0){
                int newEffort = max(abs(heights[row][col] - heights[nrow][ncol]),diff);
                if(newEffort < dist[nrow][ncol]){
                    dist[nrow][ncol] = newEffort;
                    pq.push({dist[nrow][ncol],{nrow,ncol}});
                }
                
            }
        }
        
    }
    return 0;
    
}
int main()
{
    return 0;
}