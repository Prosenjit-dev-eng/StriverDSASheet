#include<bits/stdc++.h>
using namespace std;
int n;
/*
int solve(int i, vector<int>& stoneValue){
    if(i == n) return 0;
    int res = INT_MIN;
    res = max(res, stoneValue[i] - solve(i+1, stoneValue));
    if(i + 1 < n)
        res = max(res, stoneValue[i] + stoneValue[i+1] - solve(i+2, stoneValue));
    if(i + 2 < n)
        res = max(res, stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - solve(i+3, stoneValue));
    return res;
}
string stoneGameIII(vector<int>& stoneValue) {
    n = stoneValue.size();
    int res = solve(0,stoneValue);
    if(res > 0) return "Alice";
    else if (res < 0) return "Bob";
    else return "Tie";
} */
string stoneGameIII(vector<int>& stoneValue) {
    n = stoneValue.size();
    vector<int>dp(n+1,0);
    for (int i = n-1; i >= 0; i--)
    {
        dp[i] = (stoneValue[i] - dp[i+1]);
        if(i + 1 < n)
            dp[i] = max(dp[i], stoneValue[i] + stoneValue[i+1] - dp[i+2]);
        if(i + 2 < n)
            dp[i] = max(dp[i], stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - dp[i+3]);
    }
    
    int res = dp[0];
    if(res > 0) return "Alice";
    else if (res < 0) return "Bob";
    else return "Tie";
}
int main()
{
    vector<int>stoneValue = {1,2,3,7};
    cout<<stoneGameIII(stoneValue)<<endl;
    return 0;
}