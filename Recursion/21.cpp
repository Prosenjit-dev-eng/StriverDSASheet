#include<bits/stdc++.h>
using namespace std;
    void backtrack(int i, vector<int>& nums, vector<int>& curr, vector<vector<int>>& res) {
        if(i == nums.size()) {
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        // Include
        backtrack(i+1,nums,curr,res);

        curr.pop_back();

        int idx = i+1;
        while (idx < nums.size() && nums[idx] == nums[idx-1])
        {
            idx++;
        }
        // Exclude 
        backtrack(idx,nums,curr,res);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> curr;

        backtrack(0, nums, curr, res);

        return res;
    }
int main()
{
    vector<int>nums = {1,2,2};
    vector<vector<int>>res = subsetsWithDup(nums);
    for(auto i : res){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}