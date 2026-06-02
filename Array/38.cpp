#include<bits/stdc++.h>
using namespace std;
    int maxSubArray(vector<int>& nums) {
        int b = nums[0], s = nums[0];
        int n = nums.size();
        for(int k = 1 ; k < n; k++){
            s = max(s+nums[k], nums[k]);
            b = max(s,b);
        }
        return b;
    }
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin>>nums[i];
    }
    cout<<maxSubArray(nums);
    return 0;
}