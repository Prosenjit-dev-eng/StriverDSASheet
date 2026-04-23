#include<bits/stdc++.h>
using namespace std;
// cnt <= k
int cntSubArray(vector<int>nums, int goal){
    int l = 0, r = 0, sum = 0, cnt = 0;
    int n = nums.size();
    if(goal<0){
        return 0;
    }
    while (r<n)
    {
        sum+=nums[r];
        while (sum>goal)
        {
            sum-=nums[l];
            l++;
        }
        cnt+=(r-l+1);
        r++;
    }
    return cnt;
}
int main()
{
    vector<int>nums = {1,0,1,0,1};
    int goal = 2;
    // To get the cnt == k
    cout<<(cntSubArray(nums,goal) - cntSubArray(nums,goal-1))<<endl;
    return 0;
}