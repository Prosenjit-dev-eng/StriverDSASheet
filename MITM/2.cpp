#include<bits/stdc++.h>
using namespace std;
int minAbsDifference(vector<int>& nums, int goal) {
    int n = nums.size();
    // 1.1st half the array
    int n1 = n/2;
    int n2 = n-n1;
    // 2.After returns the subsequence sum, sort the 2nd part for binary search, and lowerbound
    vector<int>sumsA;//2^n1
    for (int mask = 0; mask < (1<<n1); mask++)
    {
        int s = 0;
        for (int i = 0; i < n1; i++)
        {
            if (mask & (1<<i))
            {
                s += nums[i];
            }
            
        }
        sumsA.push_back(s);
    }
    vector<int>sumsB;//2^n2
    for (int mask = 0; mask < (1<<n2); mask++)
    {
        int s = 0;
        for (int i = 0; i < n2; i++)
        {
            if (mask & (1<<i))
            {
                s += nums[n1+i];
            }
            
        }
        sumsB.push_back(s);
    }

    sort(sumsB.begin(),sumsB.end());
    // 3.Find lowerbound or upperbound, here lowerbound(index which >= the number)
    int mini = INT_MAX;
    for(int sum1 : sumsA){
        int need = goal - sum1;
        int low = lower_bound(sumsB.begin(),sumsB.end(),need) - sumsB.begin();//ower_bound(sumsB.begin(),sumsB.end(),need), it returns a piinter ,s o we substract sumsB.begin()
        if(low < sumsB.size()){
            int sum2 = sumsB[low];
            int tot = sum1+sum2;
            mini = min(mini,abs(tot - goal));
        }
        // Also check here the previous index , like sum1 = 3, and sumsB = {1,10}, goal = 2;
        if(low > 0){
            int sum2 = sumsB[low-1];
            int tot = sum1+sum2;
            mini = min(mini,abs(tot - goal));
        }
    }
    return mini;

}
int main()
{
    vector<int>nums = {7,-9,15,-2};
    cout<<minAbsDifference(nums,-5);
    return 0;
}