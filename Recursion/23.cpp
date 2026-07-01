#include<bits/stdc++.h>
using namespace std;
    set<int>st;
    void solve(vector<int>&temp,vector<vector<int>>& res, vector<int>& nums){
        int n = nums.size();
        if(temp.size() == n){
            res.push_back(temp);
            return;
        }
        for(int i = 0; i < n; i++){
            if(st.find(nums[i]) == st.end()){
                // pick
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                solve(temp,res,nums);

                // not pick
                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }
    void solveBySwapping(int idx, vector<int>& nums, vector<vector<int>>& res){
        int n = nums.size();
        if(idx == n){
            res.push_back(nums);
            return;
        }
        for (int i = idx; i < n; i++)
        {
            swap(nums[i],nums[idx]);
            solveBySwapping(idx+1,nums,res);
            swap(nums[i],nums[idx]);

        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>temp;
        // solve(temp,res,nums);
        solveBySwapping(0,nums,res);
        return res;
    }
int main()
{
    vector<int>nums = {1,2,3};
    vector<vector<int>> res = permute(nums);
    for(auto i : res){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}