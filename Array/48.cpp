#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    #define ll long long
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n < 4) return {};
        vector<vector<int>> res;
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;// No duplicacy
            for(int j = i+1; j < n; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;// No duplicacy
                
                int k = j+1, l = n - 1;
                while(k < l){
                    ll sum = (ll)nums[i] + (ll)nums[j] + (ll) nums[k] + (ll) nums[l];
                    if(sum < target) k++;
                    else if(sum > target) l--;

                    else{
                        res.push_back({nums[i] , nums[j] ,nums[k] ,nums[l]});
                        while(k < l && (nums[k] == nums[k+1])) k++;
                        while(k < l && (nums[l] == nums[l-1])) l--;
                        k++;
                        l--;
                    }

                }
                
            }
        }  
        return res;
    }
};
int main()
{
    Solution s;
    vector<int>nums = {1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>>ans = s.fourSum(nums,target);
    for(auto v: ans){
        for(auto x: v){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}