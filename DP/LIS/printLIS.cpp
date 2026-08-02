#include<bits/stdc++.h>
using namespace std;
void printLIS(vector<int>&nums){
    int n = nums.size();
    int maxLIS = 1;
    vector<int>dp(n,1);
    vector<int>parent(n,-1);
    int LISidx = -1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(nums[j] < nums[i]){
                dp[i] = max(dp[i],dp[j]+1);
                parent[i] = j;
                if(maxLIS < dp[i]){
                    maxLIS = dp[i];
                    LISidx = i; 
                }
            }
        }
        
    }
    vector<int>res;
    while (LISidx != -1)
    {
        res.push_back(nums[LISidx]);
        LISidx = parent[LISidx];
    }
    reverse(res.begin(),res.end());
    for(auto&r : res) cout<<r<<" ";
    
}
int main()
{
    vector<int>nums = {10,9,2,5,3,7,101,18};
    printLIS(nums);
    return 0;
}