#include<bits/stdc++.h>
using namespace std;
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int pre = 1, suff = 1;
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        if(pre == 0) pre = 1;
        if(suff == 0) suff = 1;
        pre *= nums[i];
        suff *= nums[n - i - 1];
        maxi = max(maxi,max(pre,suff));
    }
    return maxi;
}
int main()
{
    vector<int> nums = {-2,3,4,-1,0,-2,3,4,0,4,6,-1,4};
    cout<<maxProduct(nums)<<endl; 
    return 0;
}