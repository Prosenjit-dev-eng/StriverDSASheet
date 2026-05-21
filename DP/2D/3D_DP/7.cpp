#include<bits/stdc++.h>
using namespace std;
int minCost(vector<vector<int>>& grid, int k) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,1e9)));
    for (int tPort = k; tPort >= 0; tPort--)
    {
        dp[n-1][m-1][tPort - 1] = 0 ;
    }
    for (int tPort = k; tPort >= 0; tPort--)
    {
        for (int i = n-1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (i == n - 1 && j == m - 1) 
                {
                    continue;
                }
                int res = 1e9; 
                
            }
            
        }
    }
        

}
int main()
{
    return 0;
}