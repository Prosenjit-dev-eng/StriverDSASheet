#include<bits/stdc++.h>
using namespace std;
/*int solve(int i, int prev, vector<int>& arr, int n){
    if(i == n) return 0;
    int take = 0;
    if(prev == -1 || arr[i] > arr[prev]) take = arr[i] + solve(i+1,i,arr,n);
    int skip = solve(i+1,prev,arr,n);
    return max(take,skip);
}*/
// Easier bottom up
/*class Solution {
public:
    int maxSumIS(vector<int>& arr) {
        int n = arr.size();

        vector<int> dp(n);

        for (int i = 0; i < n; i++) {
            dp[i] = arr[i];

            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i]) {
                    dp[i] = max(dp[i], dp[j] + arr[i]);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};*/
int maxSumIncreasingSubsequence(vector<int>& arr, int n) {
    // return solve(0,-1,arr,n);
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    // Here i = 0 and prev = -1 turns to 0;
    for (int i = n-1; i >= 0; i--)
    {
        // Why prev < i?
        // At state i, the prev element must be before i.
        for(int prev = -1; prev < i; prev++)
        {
            int take = 0;
            if(prev == -1 || arr[i] > arr[prev]) take = arr[i] + dp[i+1][i+1];
            int skip = dp[i+1][prev+1];
            dp[i][prev+1] = max(take,skip);
        }
    }
    return dp[0][0];
}
int main()
{
    vector<int>arr = {4, 1, 2, 3};
    cout<<maxSumIncreasingSubsequence(arr,4)<<endl;
    return 0;
}