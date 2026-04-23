#include<bits/stdc++.h>
using namespace std;
// By simple recursion or top-down approach
// int frogjumps(int idx,vector<int>&heights){
//     if(idx == 0) return 0;
//     int left = frogjumps(idx-1,heights)+abs(heights[idx-1] - heights[idx]);
//     int right = INT16_MAX;
//     if(idx>1)  right = frogjumps(idx-2,heights)+abs(heights[idx-2] - heights[idx]);
//     return min(left,right);

// }

// Memoisation
// int f(int idx,vector<int>&heights,vector<int>&dp){
//     if(idx == 0) return 0;// or,  if (idx == n - 1) return 0;
//     if(dp[idx] != -1) return dp[idx];  
//     int left = f(idx - 1,heights,dp)+abs((heights[idx])-(heights[idx-1]));// int left = f(idx + 1, heights, dp) + abs(heights[idx] - heights[idx + 1]);
//     int right = INT16_MAX;
//     if(idx>1) 
//     // right = f(idx + 2, heights, dp) + abs(heights[idx] - heights[idx - 2]);
//     return dp[idx] = min(left,right);
// }
// int frogjumps(int n, vector<int>&heights){
//     vector<int>dp(n+1,-1);
//     return f(n-1,heights,dp);// n-1 then should be zero
// }

// Tabulation 
int frogjumps(int n, vector<int>heights){
    vector<int>dp(n,0);
    dp[0] = 0;
    for (int i = 1; i < heights.size(); i++)
    {
        int left = dp[i-1]+abs(heights[i]-heights[i-1]);
        int right = INT16_MAX;
        if(i > 1) right = dp[i-2]+abs(heights[i]-heights[i-2]);
        dp[i] = min(left,right);
    }
    return dp[n-1];
}
// Space optimisation
int fg(int n, vector<int>heights){
    int prev1 = 0;
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int left = prev1+abs(heights[i]-heights[i-1]);
        int right = INT16_MAX;
        if(i > 1) right = prev2+abs(heights[i]-heights[i-2]);
        int curr = min(left,right);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
    
}
int main()
{
    vector<int>heights = {30,10,60,10,60,50};
    // cout<<frogjumps(heights.size()-1,heights);->top down approach
    cout<<frogjumps(heights.size(),heights)<<endl;
    cout<<fg(heights.size(),heights)<<endl;


    return 0;
}