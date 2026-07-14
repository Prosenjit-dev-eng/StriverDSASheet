#include<bits/stdc++.h>
using namespace std;
    int su(vector<int>& nums, int k){
        int n = nums.size();
        int l = 0, r = 0, cnt = 0;
        unordered_map<int,int>mp;
        while(r < n){
            mp[nums[r]]++;// first put the values
            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }

int subarraysWithKDistinct(vector<int>& nums, int k) {
    return su(nums,k) - su(nums,k-1);
        
}
int main()
{
    vector<int>nums = {1,2,1,2,3};
    int k = 2;
    cout<<subarraysWithKDistinct(nums,k)<<endl;
    return 0;
}