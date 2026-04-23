#include<bits/stdc++.h>
using namespace std;
int rob(vector<int>& nums) {
     // See here the first and the last element can be used only once
     int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        int prev2 = nums[0];
        int prev1 = max(nums[0],nums[1]);
        // Omit the last element
        for(int i=2;i<n-1;i++){
            int curr = max(prev2+nums[i],prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        int ans1 = prev1;

        prev2 = nums[1];
        prev1 = max(nums[1],nums[2]);
        // Use the last element
        for(int i=3;i<n;i++){
            int curr = max(prev2+nums[i],prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        int ans2 = prev1;
        return max(ans2,ans1);
}
int main()
{
    vector<int>nums = {2,3,2};
    cout<<rob(nums)<<endl;
    return 0;
}