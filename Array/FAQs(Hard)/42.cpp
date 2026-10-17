#include<bits/stdc++.h>
using namespace std;
vector<int>findMissingAndRepeatating(vector<int>&nums){
    int n = nums.size();
    // Find the sum of the nums
    int sum = accumulate(nums.begin(), nums.end(), 0);
    // Find sum of the natural numbers
    int sumn = (n*(n+1))/2;
    int sqSum = 0;
    for (int i = 0; i < n; i++)
    {
        sqSum += nums[i]*nums[i];
    }
    int sqSumn = (n*(n+1)*(2*n+1))/6;
    int v1 = sum - sumn;
    int v2 = sqSum - sqSumn;
    v2 = v2 / v1;
    int repeatating = (v1+v2)/2;
    int missing = (repeatating - v1);
    return {repeatating,missing};
} 
int main()
{
    vector<int>nums = {3, 5, 4, 1, 1};
    vector<int>ans = findMissingAndRepeatating(nums);
    cout<<"Repeatating: "<<ans[0]<<" "<<"Missing: "<<ans[1]<<endl;
    return 0;
}