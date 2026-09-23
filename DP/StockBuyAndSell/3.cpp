#include<bits/stdc++.h>
using namespace std;
// n*2*3 solution
// i = day, buy = 2, bool variable it is, transaction = 2 => 0,1,2
// Recursive & memo
/*int solve(vector<int>& prices, int i, int buy, int transaction, vector<vector<vector<int>>>& dp){
    if(i == prices.size() || transaction == 0) return 0;
    if(dp[i][buy][transaction] != -1) return dp[i][buy][transaction];
    if(buy){
        return dp[i][buy][transaction] = max(-prices[i] + solve(prices, i+1, 0, transaction, dp), solve(prices, i+1, 1, transaction, dp));
    }
    else{
        return dp[i][buy][transaction] = max(prices[i] + solve(prices, i+1, 1, transaction-1, dp), solve(prices, i+1, 0, transaction, dp));
    }
}
int maxProfitI(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return solve(prices, 0, 1, 2, dp);
}*/
// Tabulation
int maxProfitI(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
    // Coz we initialize it with zero , so no need to declare base case, as it is already initialized with zero
    for(int i = n-1; i >= 0; i--){
        for(int buy = 0; buy <= 1; buy++){
            for(int transaction = 1; transaction <= 2; transaction++){
                if(buy){
                    dp[i][buy][transaction] = max(-prices[i] + dp[i+1][0][transaction], dp[i+1][1][transaction]);
                }
                else{
                    dp[i][buy][transaction] = max(prices[i] + dp[i+1][1][transaction-1], dp[i+1][0][transaction]);
                }
            }
        }
    }
    return dp[0][1][2];
}

// N*4 
// i,trans = day,4 => BSBS = 2 transaction, here B = evenidx and S = oddIdx
int solve(vector<int>&prices, int i, int trans, int n, vector<vector<int>>& dp){
    if(i == n || trans == 4) return 0;
    if(dp[i][trans] != -1) return dp[i][trans];
    if(trans%2 == 0){
        return dp[i][trans] = max(-prices[i] + solve(prices, i+1, trans+1, n, dp), solve(prices, i+1, trans, n, dp));
    }
    else{
        return dp[i][trans] = max(prices[i] + solve(prices, i+1, trans+1, n, dp), solve(prices, i+1, trans, n, dp));
    }
}
int maxProfit(vector<int>& prices){
    // return solve(prices, 0, 0, n, dp);
    int n = prices.size();
    // To escape out of bound we use n + 1 and 5 used for transaction as we are using 0 based indexing and we need to go till 4
    vector<vector<int>>dp(n,vector<int>(4,-1));
    for (int i = n-1; i >= 0; i--)
    {
        for (int trans = 3; trans >= 0; trans--)
        {
            if(trans%2 == 0){//Buy
                dp[i][trans] = max(-prices[i] + (i+1<n?dp[i+1][trans+1]:0), (i+1<n?dp[i+1][trans]:0));
            }
            else{// Sell
                dp[i][trans] = max(prices[i] + (i+1<n?dp[i+1][trans+1]:0), (i+1<n?dp[i+1][trans]:0));
            }
        }
    }
    return dp[0][0];
}

int main()
{
    return 0;
}