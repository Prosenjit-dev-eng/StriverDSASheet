#include<bits/stdc++.h>
using namespace std;
/*int n;
int t[2501][2501];
int solve(int i, int prevIdx,vector<int>& nums){
    if(i == n) return 0;
    if(t[i][prevIdx] != -1) return t[i][prevIdx];
    int take = 0,skip = 0;
    if(prevIdx == -1 || nums[i] > nums[prevIdx]){
        take = 1+solve(i+1,i,nums);
    }
    skip = solve(i+1,prevIdx,nums);
    return t[i][prevIdx] = max(skip,take);
}
int lengthOfLIS(vector<int>& nums) {
    n = nums.size();
    memset(t,-1,sizeof(t));
    return solve(0,-1,nums);
}*/
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    // dp[n][*] = 0 (already initialized)
    for (int i = n-1; i >=0 ; i--)
    {
        int take = 0;
        int skip = 0;
        for (int j = i-1; j >= -1; j--)
        {
            if(j == -1 || nums[i] > nums[j]) take = 1+dp[i+1][i+1];
            skip = dp[i+1][j+1];

            dp[i][j+1] = max(take,skip);
        }
        
    }
    return dp[0][0];
    
}
int main()
{
    return 0;
}