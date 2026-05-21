#include <bits/stdc++.h>
using namespace std;
// Recursive approach
/*int solve(int i, int j){
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;

        int up = solve(i-1,j);
        int left = solve(i,j-1);
        return up+left;
}*/
// Memoisation-> T.C. = o(m*n)
// S.C. = o(n) + o(m-1+n-1) here o(n) stack space
// int solve(int i, int j, vector<vector<int>> &dp){
//         if(i == 0 && j == 0) return 1;
//         if(i < 0 || j < 0) return 0;
//         if(dp[i][j] != -1) return dp[i][j];
//         int up = solve(i-1,j,dp);
//         int left = solve(i,j-1,dp);
//         return dp[i][j] = up+left;
// }
// Tabulatiion
/*int solve(int m, int n, vector<vector<int>> &dp){
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue; // Skip the rest of the loop and continue with the next iteration.
            }
            int up = 0, left = 0;
            if (i>0)
            {
                up = dp[i-1][j];
            }
            if (j > 0)
            {
                left = dp[i][j-1];
            }
            dp[i][j] = up+left;

        }

    }
    return dp[m-1][n-1];

} */
// Space optimisation
int uniquePaths(int m, int n)
{
    // int ans = solve(m-1,n-1);
    // vector<vector<int>>dp(m,vector<int>(n,-1));
    // return solve(m,n,dp);
    vector<int> prev(m, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n, 0);
        for (int j = 0; j < n; j++)
        {

            if (i == 0 && j == 0)
            {
                temp[j] = 1;
                continue; // Skip the rest of the loop and continue with the next iteration.
            }
            int up = 0, left = 0;
            if (i > 0)
            {
                up = prev[j];
            }
            if (j > 0)
            {
                left = temp[j - 1];
            }
            temp[j] = up + left;
        }
        prev = temp;
    }
    // The result is stored in the last cell of the previous row (n-1).
    return prev[n - 1];
}
int main()
{
    int m = 25, n = 9;
    cout << uniquePaths(25, 9) << endl;
    return 0;
}