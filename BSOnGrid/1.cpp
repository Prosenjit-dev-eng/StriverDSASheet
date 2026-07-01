// Leetcode 2812
#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> dir{{1,0},{-1,0},{0,-1},{0,1}};
bool check(vector<vector<int>>&distNearestThief, int mid){
    queue<pair<int,int>>q;
    vector<vector<bool>> vis(n,vector<bool>(n,false));
    q.push({0,0});
    vis[0][0] = true;
    while (!q.empty())
    {
            int curr_i = q.front().first;
            int curr_j = q.front().second;
            q.pop();

            if (curr_i == n-1 && curr_j == n - 1)
            {
                return true;
            }
            for(auto& d: dir){
                int newi = curr_i + d[0];
                int newj = curr_j + d[1];

                if (newi>=0 && newi < n && newj >= 0 && newj < n && !vis[newi][newj]){
                    if(distNearestThief[newi][newj]<mid){
                        continue;// reject this cell

                    }
                    q.push({newi,newj});
                    vis[newi][newj] = true;
                }
            }
    }
    return false;
    
}
int maximumSafenessFactor(vector<vector<int>>& grid) {
    n = grid.size();
    // Step -1: Precalculation of distNearestThief
    vector<vector<int>>distNearestThief(n,vector<int>(n,-1));
    queue<pair<int,int>>q;
    vector<vector<bool>>vis(n,vector<bool>(n,false));

    // Push all cells in queue where thieves are present
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j])
            {
                q.push({i,j});
                vis[i][j] = true;
            }
            
            
        }
        
    }
    
    // Multisource BFS
    int level = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int curr_i = q.front().first;
            int curr_j = q.front().second;
            q.pop();

            distNearestThief[curr_i][curr_j] = level; // No calculation put the level
            for(auto& d: dir){
                int newi = curr_i + d[0];
                int newj = curr_j + d[1];

                if (newi<0 || newi >= n || newj < 0 || newj >= n || vis[newi][newj]) continue;
                q.push({newi,newj});
                vis[newi][newj] = true;
            }
        }
        level++;
        
    }
    // Apply BS on Safe Factor
    int l = 0,  r = 400;
    int res = 0;
    while (l <= r)
    {
        int mid = l + (r-l)/2;
        if (check(distNearestThief,mid))
        {
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
        
    }
    
    return res;
}
int main()
{
    return 0;
}