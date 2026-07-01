#include<bits/stdc++.h>
#include<tuple>
using namespace std;
vector<int> maxCombinations(vector<int>& nums1, vector<int>& nums2, int k) {
   if (nums1.empty() || nums2.empty()) return {};
   vector<int> res;
   sort(nums1.begin(),nums1.end(),greater<int>());
   sort(nums2.begin(),nums2.end(),greater<int>()); 

   priority_queue<tuple<int,int,int>> pq;
   set<pair<int,int>>visited;// The indices of every possible sum

   pq.push({nums1[0]+nums2[0],0,0});
   visited.insert({0,0});

   while (k-- && !pq.empty())
   {
    auto t = pq.top();
    int sum = get<0>(t);
    int i   = get<1>(t);
    int j   = get<2>(t);
    pq.pop();
    res.push_back(sum);
    if (i+1 < nums1.size() && !visited.count({i+1,j}))
    {
        pq.push({nums1[i+1] + nums2[j],i+1,j});
        visited.insert({i+1,j});
    }
    if (j+1 < nums2.size() && !visited.count({i,j+1}))
    {
        pq.push({nums1[i] + nums2[j+1],i,j+1});
        visited.insert({i,j+1});
    }
   }
   return res;
}

int main()
{
    vector<int> nums1 = {7, 3};
    vector<int> nums2 = {1, 6};
    int k = 2;
    vector<int>res = maxCombinations(nums1,nums2,k);
    for(int r : res){
        cout<<r<<" ";
    }
    return 0;
}