#include<bits/stdc++.h>
using namespace std;
// Recursive approach
/*    int solve(int i, int j,vector<vector<int>>& grid){
        if(i == 0 && j == 0) return grid[i][j];
        // If out of bounds, return large number
        if(i < 0 || j < 0) return 1e9;

        int up = grid[i][j]+solve(i-1,j,grid);
        int left = grid[i][j]+solve(i,j-1,grid);

        return min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(),  n = grid[0].size();
        return solve(m-1,n-1,grid);
    }
        // T.C. = O(2^(m+n))
        // S.C. = O(m+n)
*/
// Memoisation
/*
int solve(int i, int j,vector<vector<int>>& grid, vector<vector<int>>&dp){
        if(i == 0 && j == 0) return grid[i][j];
        // If out of bounds, return large number
        if(i < 0 || j < 0) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = grid[i][j]+solve(i-1,j,grid,dp);
        int left = grid[i][j]+solve(i,j-1,grid,dp);

        return dp[i][j] = min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,grid,dp);
    }
        //T.C. = Time Complexity: O(N*M), at max, there will be N*M calls of recursion.
        // S.C. = Space Complexity: O(M+N) + O(N*M), additional space for recursion stack and memo table.

*/
//Tabulation
/*
        int solve(int m, int n,vector<vector<int>>& grid, vector<vector<int>>&dp){

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                    continue;
                } 
                int up = grid[i][j], left = grid[i][j];
                if(i > 0)  up += dp[i-1][j];
                else up = 1e9;
                if(j > 0)  left += dp[i][j-1];
                else left = 1e9;
                dp[i][j] = min(up,left);
            }
        }

        return dp[m-1][n-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        return solve(m,n,grid,dp);
    }
        Time Complexity: O(N*M), entire grid is visited atleast once.
        Space Complexity: O(N*M), space used for DP array.
*/
// Space optimisation

int minPathSum(vector<vector<int>>& grid) {
        // Create 1D vector for previous row
        int n = grid.size(), m = grid[0].size();
        vector<int> prev(m, 0);
    
        // Loop through each row
        for (int i = 0; i < n; i++) {
        
            // Create temp vector for current row
            vector<int> temp(m, 0);
        
            // Loop through each column
            for (int j = 0; j < m; j++) {
            
                // If at the start cell
                if (i == 0 && j == 0)
                    temp[j] = grid[i][j];
                else {
                    
                    // Take up direction if valid
                    int up = grid[i][j];
                    if (i > 0)
                        up += prev[j];
                    else
                        up += 1e9;
                    
                    // Take left direction if valid
                    int left = grid[i][j];
                    if (j > 0)
                        left += temp[j - 1];
                    else
                        left += 1e9;
                    
                    // Take minimum of both directions
                    temp[j] = min(up, left);
                }
            }
    
            // Move current row to previous
            prev = temp;
        }
    
        // Return result at destination
        return prev[m - 1];
    }
// Time Complexity: O(N*M), every element of grid is visited atleast once.
// Space Complexity: O(N), we only use one array for storing rows.

int main()
{
    vector<vector<int>> grid = {{1,3,1},
                                {1,5,1},
                                {4,2,1}};
    cout << minPathSum(grid) << endl;   

    return 0;
}