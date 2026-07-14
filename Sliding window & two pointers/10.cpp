#include<bits/stdc++.h>
using namespace std;
 vector<int> distinctNumbers(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> mp;

        // First window
        for (int i = 0; i < k; i++) {
            mp[nums[i]]++;
        }

        ans.push_back(mp.size());

        // Remaining windows
        for (int i = k; i < n; i++) {
            // Remove outgoing element
            mp[nums[i - k]]--;
            if (mp[nums[i - k]] == 0)
                mp.erase(nums[i - k]);

            // Add incoming element
            mp[nums[i]]++;

            ans.push_back(mp.size());
        }

        return ans;
 }
int main()
{
    vector<int>nums = {1,2,3,2,2,1,3};
    int k = 3;
    vector<int>ans = distinctNumbers(nums,k);
    for(auto &a : ans) cout<<a<<" ";
    return 0;
}