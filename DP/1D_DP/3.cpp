#include<bits/stdc++.h>
using namespace std;
// Maximum sum of non-adjacent elements

// Recursion

/*int maximumNonAdjacentSumUtil(int n, vector<int>&nums){
    if(n == 0) return nums[0];
    if(n < 0) return 0;

    int pick = nums[n] + maximumNonAdjacentSumUtil(n-2,nums);
    int notpick = 0 + maximumNonAdjacentSumUtil(n-1,nums);

    return max(pick,notpick);
}*/
// Memoisation
// in memoisation we've to pass dp array also
// int solve(vector<int>nums,int n, vector<int>&dp){
//     if(n == 0) return nums[0];
//     if(n < 0) return 0;
//     if(dp[n] != -1) return dp[n];
//     int pick = nums[n] + maximumNonAdjacentSumUtil(nums,n-2);
//     int notpick = 0 + maximumNonAdjacentSumUtil(nums,n-1);
//     dp[n] = max(pick,notpick);
//     return dp[n];
// }
// Tabulation
/*int solvetab(vector<int>&nums){
    int n = nums.size();
    vector<int>dp(n,0);
    dp[0] = nums[0];
    dp[1] = max(nums[0],nums[1]);// this has to be declared
    // because when n=1, dp[1] will give out of bound error
    for(int i = 2; i < n; i++){
        int pick = dp[i-2]+nums[i];
        int notpick = dp[i-1]+0;
        dp[i] = max(pick,notpick);
    }

    return dp[n-1];
}*/
int spaceOtimised(vector<int>&nums){
    int n = nums.size();
    int prev1 = nums[0];
    int prev2 = 0;
    for(int i = 1; i < n; i++){
        int pick = nums[i];
        if(i > 1) pick += prev2;
        int notpick = 0 + prev1;
        int curr = max(pick,notpick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int maximumNonAdjacentSumUtil(vector<int>&nums){
    int n = nums.size();
    // vector<int>dp(n,-1);
    return spaceOtimised(nums);
}
int main()
{
    // vector<int> nums = {3, 2, 5, 10, 7};
    // int n = nums.size();
    // int result = maximumNonAdjacentSumUtil(n-1, nums);
    // cout << "Maximum sum of non-adjacent elements: " << result << endl;
    vector<int> nums = {3,2,5,10,7};
    cout<<maximumNonAdjacentSumUtil(nums);
    
    return 0;
}