#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>&nums, int l, int r){
    int p = nums[l];
    int i = l;
    int j = r;
    while (i<=j)
    {
        if (nums[i] < p && nums[j] > p)
        {
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
        if (nums[i] >= p)
        {
            i++;
        }
        if(nums[j] < p) j--;
        
        
    }
    swap(nums[l],nums[j]);
    return j;
    
}
int findKthLarget(vector<int>&nums, int k){
    int n = nums.size();
    int l = 0, r = n - 1;
    int pivot = 0;
    // Kth largest
    while (true)
    {
        pivot = partition(nums,l,r);
        if (pivot ==  k- 1)
        {
            break;
        }
        else if (pivot > k - 1)
        {
            r = pivot - 1;// want 2nd largest find 4th largest 
        }
        else l = pivot + 1;
        
        
    }
    return nums[pivot];
}
int main()
{
    vector<int>nums = {3,2,1,5,6,4};
    int k = 2;
    cout<<findKthLarget(nums,k)<<endl;
    return 0;
}