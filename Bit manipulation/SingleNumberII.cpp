#include<bits/stdc++.h>
using namespace std;
    // optimal
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 1; i < n; i+=3){
            if(nums[i-1] != nums[i]) return nums[i-1];
        }
        return nums[n-1];
    }
    // Most optimal
    int singleNumberbyo(vector<int>& nums) {
        int n = nums.size();
        // using Buckets
        int ones = 0 , twos = 0;
        for (int i = 0; i < n; i++)
        {
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;

        }
        return ones;
    }

int main()
{
    vector<int>nums = {2,2,2,1};
    cout<<singleNumber(nums)<<endl;
    cout<<singleNumberbyo(nums)<<endl;

    return 0;
}