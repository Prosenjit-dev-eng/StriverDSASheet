#include<bits/stdc++.h>
using namespace std;
int solve(int i, bool canJump, vector<int>&nums){
    if(i>=nums.size() || i < 0) return 0;
    int two = nums[i+2] + solve(i+2,true,nums);
    int one = nums[i-1] + solve(i-1,true,nums);
    return min(two, one);
}
int maxSteps(vector<int>&nums){
    return solve(1,true,nums);
}
int main()
{
    vector<int>nums = {2,5,8};
    cout<<maxSteps(nums)<<endl;
    return 0;
}