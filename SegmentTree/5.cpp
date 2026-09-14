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

    segTree[i] = max(segTree[2*i+1],segTree[2*i+2]);

}
bool queryST(int i, int l, int r, int val, vector<int>&segTree){
    if(val > segTree[i]) return false;
    if(l == r) {
        segTree[i] = -1;
        return true;
    }
    int mid = l + (r-l)/2;
    bool placed = false;
    if(segTree[2*i+1] >= val) {
        placed = queryST(2*i+1,l,mid,val,segTree);
    } else {
        placed =  queryST(2*i+2,mid+1,r,val,segTree);
    }
    segTree[i] = max(segTree[2*i+1],segTree[2*i+2]);// it is important to update the segment tree after placing the fruit, bcz we use -1 later on
    return placed;
}
int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    int n = fruits.size();
    vector<int> segTree(4*n,-1);
    buildSegmentTree(0,0,n-1,baskets,segTree);
    int unplaced = 0;
    for(auto f : fruits) {
        if(!queryST(0,0,n-1,f,segTree)) {
            unplaced++;
        }
    }
    return unplaced;
}
int main()
{
    return 0;
}