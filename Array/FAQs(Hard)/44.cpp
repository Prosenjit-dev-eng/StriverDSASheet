#include<bits/stdc++.h>
using namespace std;
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int f = floor(n/3);
        vector<int>res;
        unordered_map<int,int>mp;
        for(int &i : nums){
            mp[i]++;
        }
        for(auto &it : mp){
            if(it.second > f) res.push_back(it.first);
        }
        return res;
    }

int main()
{
    vector<int>v = {1,2};
    vector<int>ans = majorityElement(v);
    for(auto &it : ans){
        cout<<it<<" ";
    }
    return 0;
}