#include<bits/stdc++.h>
using namespace std;
// Recursion
    // int f(int i,int j,vector<vector<int>>& triangle){
    //     int n = triangle.size();
    //     if(i == n-1) return triangle[i][j];
    //     int d = triangle[i][j]+f(i+1,j,triangle);// down
    //     int diag = triangle[i][j]+f(i+1,j+1,triangle);// diagonal
    //     return min(d,diag);
    // }
    // int minimumTotal(vector<vector<int>>& triangle) {

    //     return f(0,0,triangle);
    // }
    // Time Complexity: O(2^(N*M)), as at every cell we have 2 choices.
    // Space Complexity: O(N), for the recursion stack.

// Memoization
    // int f(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
    //     int n = triangle.size();
    //     if(i == n-1) return triangle[i][j];
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int d = triangle[i][j]+f(i+1,j,triangle,dp);// down
    //     int diag = triangle[i][j]+f(i+1,j+1,triangle,dp);// diagonal
    //     return dp[i][j] = min(d,diag);
    // }
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int n = triangle.size();
    //     vector<vector<int>> dp(n,vector<int>(n,-1));
    //     return f(0,0,triangle,dp);
    // }
    // Time Complexity: O(N*M), as at max there will be N*M calls.
    // Space Complexity: O(N*M) + O(N), for the dp array and recursion stack.
// Tabulation
int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // Start from second-last row and move upward
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                // Add current value + min of two possible paths below
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0]; // Top element becomes the answer


    }    // Time Complexity: O(N*M), as we traverse the entire triangle.
         // Space Complexity: O(1), as we are modifying the input triangle.
int main()
{
    vector<vector<int>> grid = {{1},
                                {1,5},
                                {4,2,1}};
    cout<<minimumTotal(grid)<<endl;
    return 0;
}