#include<bits/stdc++.h>
using namespace std;
// Make the Segment Tree
void buildSegmentTree(int i, int l, int r,vector<int>& arr, vector<int>&segTree){
    if(l == r) {
        segTree[i] = arr[l];
        return;
    }
    int mid = l + (r-l)/2;
    // l to mid
    buildSegmentTree(2*i+1, l, mid, arr, segTree);
    // mid + 1 to r
    buildSegmentTree(2*i+2, mid+1, r, arr, segTree);

    segTree[i] = segTree[2*i+1]+segTree[2*i+2];

}
// Range Sum Query
int rangeSumQuery(int s, int e, int i, int l, int r,vector<int>&segTree){
    // if l,r Outside the range
    if(l > e || r < s) return 0;
    // Inside
    if(l >= s && r <= e) return segTree[i];
    // Partially Overlapping
    int mid = l+(r-l)/2;

    return rangeSumQuery(s,e,2*i+1,l,mid,segTree) + rangeSumQuery(s,e,2*i+2,mid+1,r,segTree);

}
vector<int> querySum(vector<int>& arr, vector<vector<int>>& queries) {
    int n = arr.size();
    vector<int>segTree(4*n,0);
    buildSegmentTree(0,0,n-1,arr,segTree);
    int q = queries.size();
    vector<int> result;
    for (int i = 0; i < q; i++)
    {
        int start = queries[i][0]-1;
        int end = queries[i][1]-1;
        result.push_back(rangeSumQuery(start,end,0,0,n-1,segTree));
    }
    return result;
    
}
int main()
{
    vector<int>arr = {26, 30, 48, 29, 8};
    vector<vector<int>> queries = {{4, 4}, {2, 3}};
    vector<int>res = querySum(arr,queries);
    for(auto r : res) cout<< r <<endl;
    return 0;
}