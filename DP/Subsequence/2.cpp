#include<bits/stdc++.h>
using namespace std;
/*int f(int idx, int amount, vector<int>& coins){
    if (idx == 0)
    {
        if (amount % coins[0] == 0)
        {
            return amount / coins[0];
        }
        else return 1e9;
        
    }
    int notPick = f(idx - 1, amount, coins);
    int pick = INT_MAX;
    if (coins[idx] <= amount)
    {
        pick = 1+f(idx,amount - coins[idx],coins);
    }
    return min(pick,notPick);
}
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    int ans =  f(n - 1, amount,coins);
    return ans >= 1e9 ? -1 : ans;
}*/
/*int f(int idx, int amount, vector<int>& coins, vector<vector<int>>&dp){
    if (idx == 0)
    {
        if (amount % coins[0] == 0)
        {
            return amount / coins[0];
        }
        else return 1e9;
        
    }
    if(dp[idx][amount] != -1) return dp[idx][amount]; 
    int notPick = f(idx - 1, amount, coins,dp);
    int pick = INT_MAX;// return minimum so INT_MAX
    if (coins[idx] <= amount)
    {
        pick = 1+f(idx,amount - coins[idx],coins,dp);
    }
    return dp[idx][amount] = min(pick,notPick);
}
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));// idx and amount changes, so 2d dp
    int ans =  f(n - 1, amount,coins,dp);
    return ans >= 1e9 ? -1 : ans;
}*/

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>>dp(n,vector<int>(amount+1,-1));// idx and amount changes, so 2d dp
    for (int i = 0; i <= amount; i++)
    {
        if(i%coins[0] == 0) dp[0][i] = i/coins[0];
        else dp[0][i] = 1e9; 
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            int notPick = dp[i-1][j];
            int pick = INT_MAX;// return minimum so INT_MAX
            if (coins[i] <= j)
            {
                pick = 1+dp[i][j - coins[i]];
            }
            dp[i][j] = min(pick,notPick);
        }
        
    }
    int ans = dp[n-1][amount];
    return ans >= 1e9 ? -1 : ans;
    
}
int main()
{
    vector<int>coins = {1,2,3};
    int amount = 8;
    cout<<"Minimum no of coins: "<< coinChange(coins,amount)<<endl;
    return 0;
}