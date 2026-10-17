#include<bits/stdc++.h>
using namespace std;

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int midx = m - 1;
        int nidx = n - 1;
        int right = m + n - 1;

        while (nidx >= 0) {
            if (midx >= 0 && nums1[midx] > nums2[nidx]) {
                nums1[right] = nums1[midx];
                midx--;
            } else {
                nums1[right] = nums2[nidx];
                nidx--;
            }
            right--;
        }
    }

int main()
{
    vector<int>nums1 = {1,2,3,0,0,0};
    vector<int>nums2 = {2,5,6};
    int m = 3 , n = 3;
    merge(nums1,m,nums2,n);
    for (int i = 0; i < m+n; i++)
    {
        cout<<nums1[i]<<",";
    }
    
    return 0;
}