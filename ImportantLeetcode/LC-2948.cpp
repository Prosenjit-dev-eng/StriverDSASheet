#include<bits/stdc++.h>
using namespace std;
vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(nums[j] < nums[i] && abs(nums[j] - nums[i]) <= limit) {
                swap(nums[i], nums[j]);
                if(limit == 0) return nums;
            }
        }
    }
    return nums;
}
    
int main()
{
    return 0;
}