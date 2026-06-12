#include<bits/stdc++.h>
using namespace std;
int cntXOR(vector<int>& nums,int k){
    int n = nums.size();
    int cnt = 0;
    unordered_map<int,int>mp;// Forntxor -> Index
    mp[0] = 1;
    int frontXOR = 0;
    for (int i = 0; i < n; i++)
    {
        frontXOR ^= nums[i];
        int x = frontXOR^k;
        if(mp.find(x) != mp.end()) cnt += mp[x];
        mp[frontXOR]++;
    }
    return cnt;
    
}
int main()
{
    vector<int>nums = {4,2,2,6,4};
    cout<<cntXOR(nums,6)<<endl;
    return 0;
}