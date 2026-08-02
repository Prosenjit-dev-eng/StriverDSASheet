#include<bits/stdc++.h>
using namespace std;

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2 == 1) return false;
        int s = sum/2;
        vector<vector<bool>>dp(n,vector<bool>(s+1,false));
        for(int i = 0; i < n; i++) dp[i][0] = true;
        if(nums[0] <= s) dp[0][nums[0]] = true;
        for(int i = 1; i < n; i++){
            for(int j = 1; j < s+1; j++){
                bool notpick = dp[i-1][j];
                bool pick = false;
                if(j >= nums[i]) pick = dp[i-1][j - nums[i]];
                dp[i][j] = pick || notpick;
            }
        }
        return dp[n-1][s];

    }
int main()
{
    vector<int>nums = {1,5,11,5};
    cout<<canPartition(nums)<<endl;
    return 0;
}