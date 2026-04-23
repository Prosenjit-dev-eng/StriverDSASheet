#include<bits/stdc++.h>
#define ll
using namespace std;

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n < 3) return {};
        vector<vector<int>>res;
        for(int i = 0; i < n;i++){
            // Duplicacy for fixed n1
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int n1 = nums[i];
            int target = -n1;
            int j = i+1, k = n - 1;
            while(j < k){
                // Duplicacy avoided by using j++ and k--
                int sum = (nums[j]+nums[k]);
                if(sum > target) k--;
                else if(sum < target) j++;
                else{
                    while(j < k && (nums[j] == nums[j+1])) j++;
                    while(j < k && (nums[k] == nums[k-1])) k--;
                    res.push_back({n1,nums[j],nums[k]});
                    j++;
                    k--;
                }

            }

        }
        return res;
    }
int main()
{
    vector<int>nums = {-1,0,1,2,-1,-4};
    vector<vector<int>>ans = threeSum(nums);
    for(auto v: ans){
        for(auto x: v){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}