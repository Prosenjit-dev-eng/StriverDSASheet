#include<bits/stdc++.h>
using namespace std;
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

    segTree[i] = min(segTree[2*i+1],segTree[2*i+2]);

}
// Range min query
int rmq(int s, int e, int i, int l, int r,vector<int>&segTree){
    // if l,r Outside the range
    if(l > e || r < s) return INT_MAX;
    // Inside
    if(l >= s && r <= e) return segTree[i];
    // Partially Overlapping
    int mid = l+(r-l)/2;

    return min(rmq(s,e,2*i+1,l,mid,segTree),rmq(s,e,2*i+2,mid+1,r,segTree));
}
vector<int> rangeMinQuery(vector<int>& arr, vector<vector<int>>& queries) {
    int n = arr.size();
    vector<int>segTree(4*n,0);
    buildSegmentTree(0,0,n-1,arr,segTree);
    vector<int>res;
    for(auto q : queries){
        int s = q[0];
        int e = q[1];
        res.push_back(rmq(s,e,0,0,n-1,segTree));
    }    
    return res;
}

int main()
{
    vector<int>arr = {1,2,3,4};
    vector<vector<int>> queries = {{0, 2}, {2, 3}};
    vector<int>res = rangeMinQuery(arr,queries);
    for(auto r : res) cout<<r<<endl;
    return 0;
}