#include<bits/stdc++.h>
using namespace std;
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-2] != nums[n-1]) return nums[n-1];
        int l = 1, h = n - 2;
        while(l <= h){
            int mid = l + (h - l)/2;
            // Even , odd then the expected value in the right half
            // if mid is a odd index, so the other value should be in mid - 1 index
            // if mid is a even index, so the other value should be in mid + 1 index

            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid+1]){
                return nums[mid];
            }
            else if((mid%2 == 1 && nums[mid] == nums[mid - 1]) || (mid%2 == 0 && nums[mid] == nums[mid + 1])){
                l = mid+1;
            }
            else h = mid - 1;
        }
        return -1;
    }
int main()
{
    vector<int>nums = {1,1,2,2,3,3,4,5,5,6,6};
    cout<<singleNonDuplicate(nums)<<endl;
    return 0;
}