#include<bits/stdc++.h>
using namespace std;
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(abs(target) > sum) return 0;
        if((sum+(target))%2 != 0) return 0;
        int p = (sum+target)/2;
        vector<vector<int>>dp(n,vector<int>(p+1,0));
        dp[0][0] = 1;
        if (nums[0] <= p)
            dp[0][nums[0]] += 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < p+1; j++){
                int notpick = dp[i-1][j];
                int pick = 0;
                if(j >= nums[i]) pick = dp[i-1][j - nums[i]];
                dp[i][j] = pick + notpick;
            }
        }
        return dp[n-1][p];
    }
int main()
{
    vector<int>nums = {1,1,1,1,1};
    cout<<findTargetSumWays(nums,3)<<endl;
    return 0;
}