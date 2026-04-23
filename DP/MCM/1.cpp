#include <bits/stdc++.h>
using namespace std;
// Recursive approach
/*int f(int i,int j,vector<int>& arr){
    if(i >= j) return 0;
    int mini = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int steps = f(i,k,arr) + f(k+1,j,arr) + (arr[i-1] * arr[k] * arr[j]);
        mini = min(mini,steps);
    }
    return mini;
}
int matrixMaultipication(vector<int>& arr, int n){
    int i = 1;
    int j = n - 1;
    return f(i,j,arr);
}*/
// Memoisation
/*int f(int i,int j,vector<int>& arr, vector<vector<int>>&dp){
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int mini = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int steps = f(i,k,arr,dp) + f(k+1,j,arr,dp) + (arr[i-1] * arr[k] * arr[j]);
        mini = min(mini,steps);
    }
    return dp[i][j] = mini;
}
int matrixMaultipication(vector<int>& arr, int n){
    int i = 1;
    int j = n - 1;
    vector<vector<int>>dp(n,vector<int>(n,-1));
    return f(i,j,arr,dp);
}*/

int matrixMaultipication(vector<int> &arr, int n)
{

    vector<vector<int>> dp(n, vector<int>(n, 0));
    // for (int i = 0; i < n; i++)
    // {
    //     dp[i][i] = 0;
    // }

    // if(dp[i][j] != -1) return dp[i][j];
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < n; j++)
        {

            int mini = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int steps = dp[i][k] + dp[k + 1][j] + (arr[i - 1] * arr[k] * arr[j]);
                mini = min(mini, steps);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][n - 1];
}
int main()
{
    vector<int> arr = {10, 20, 30, 40, 50};
    int n = arr.size();
    cout << "Minimum number of multiplications is " << matrixMaultipication(arr, n) << endl;
    return 0;
}