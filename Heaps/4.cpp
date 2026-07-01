#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int>mp;
    for(auto &it : nums) mp[it]++;
    priority_queue<P,vector<P>,greater<P>>pq;
    for(auto &it : mp)
    {
        int freq = it.second;
        int value = it.first;
        pq.push({freq,value});
        if (pq.size() > k) pq.pop();
    }
    vector<int> result;
    while (!pq.empty()) {
        result.push_back(pq.top().second);
        pq.pop();
    }
    return result;
}
int main()
{
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> res = topKFrequent(nums,k);
    for(int r : res){
        cout<<r<<" ";
    }
    return 0;
}