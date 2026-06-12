#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class SegmentTree{
    public:
    vector<int>segmentTree;
    bool isMinTRee;
    SegmentTree(vector<int>&nums, bool flag){
        int n = nums.size();
        this->isMinTRee = flag;

        segmentTree.resize(4*n);
        buiildSegmentTree(0,0,n-1,nums);
    }
    void buiildSegmentTree(int i, int l, int r, vector<int>&nums){
        if (l == r)
        {
            segmentTree[i] = nums[l];
            return;
        }
        int mid = l+(r-l)/2;
        buiildSegmentTree(2*i+1,l,mid,nums);
        buiildSegmentTree(2*i+2,mid+1,r,nums);

        if(isMinTRee) segmentTree[i] = min(segmentTree[2*i+1], segmentTree[2*i+2]);
        else segmentTree[i] = max(segmentTree[2*i+1],segmentTree[2*i+2]);
    }

    int querySegmentTree(int start, int end, int i, int l, int r){
        // No overlap
        if(l > end || r < start){
            return isMinTRee? INT_MAX : INT_MIN;
        }

        // Complete overlap
        if(start <= l && r <= end){
            return segmentTree[i];
        }

        int mid = l + (r-l)/2;
        int a = querySegmentTree(start,end, 2*i+1,l,mid);
        int b = querySegmentTree(start,end, 2*i+2,mid+1,r);
        
        return isMinTRee ? min(a,b) : max(a,b);
    }
    int query(int l, int r, int n){
        return querySegmentTree(l,r,0,0,n-1);
    }
};
ll getValue(int l, int r, SegmentTree& minST, SegmentTree& maxST, int n){
    int minEl = minST.query(l,r,n);
    int maxEl = maxST.query(l,r,n);
    return (ll)maxEl - minEl;
}
long long maxTotalValue(vector<int>& nums, int k) {
    int n = nums.size();

    SegmentTree minST(nums,true);// true for minimum
    SegmentTree maxST(nums,false);// false is for maximum

    // {val,l,r}
    priority_queue<tuple<ll,int,int>> pq;
    //Step-I
    // Initialise maxheap
    for (int l = 0; l < n; l++)
    {
        ll value = getValue(l,n-1,minST,maxST,n);
        pq.push({value,l,n-1});
    }
    ll res = 0;
    while (k--)
    {
        ll value;
        int l, r;
        tie(value, l, r) = pq.top();
        pq.pop();
        res += value;

        if (l <= r-1) {
            ll nextBestValue = getValue(l,r-1,minST,maxST,n);
            pq.push({nextBestValue,l,r-1});
        }
    }
    return res;
    
}
int main()
{
    return 0;
}