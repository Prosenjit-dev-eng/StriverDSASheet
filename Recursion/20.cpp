#include<bits/stdc++.h>
using namespace std;
void solve(int idx, int currSum,vector<int>& nums, vector<int>&findsum){
    if (idx == nums.size())
    {
        findsum.push_back(currSum);
        return;
    }
    solve(idx+1,currSum+nums[idx], nums,findsum);// pick
    solve(idx+1,currSum, nums,findsum);// unpick

}

vector<int>subsetSum(vector<int>& nums){
    vector<int>findSum;
    solve(0, 0, nums, findSum);
    sort(findSum.begin(),findSum.end());
    return findSum;
}
int main()
{
    vector<int>nums = {3,2,1};
    vector<int>res = subsetSum(nums);
    for(auto v : res){
        cout<<v<<endl;
    }
    return 0;
}