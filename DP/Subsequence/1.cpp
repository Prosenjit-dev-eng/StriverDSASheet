#include<bits/stdc++.h>
using namespace std;
// Subset sum equal to target
// Recursive approach

/*bool f(int idx, int target,vector<int>& arr){
    if(target == 0) return true;
    if(idx == 0) return target == arr[0];

    bool notPick = f(idx-1, target, arr);
    bool pick = false;
    if(target >= arr[idx]) pick = f(idx-1, target-arr[idx],arr);
    return pick||notPick;
}
bool subsetSumToK(int n, int k, vector<int>& arr){
    int idx = n-1;
    int target = k;
    f(idx, target, arr);
}*/
// Memoisation
/*bool f(int idx, int target,vector<int>& arr,vector<vector<bool>>&dp){
    if(target == 0) return true;
    if(idx == 0) return target == arr[0];
    if(dp[idx][target]!=-1) return dp[idx][target];
    bool notPick = f(idx-1, target, arr,dp);
    bool pick = false;
    if(target >= arr[idx]) pick = f(idx-1, target-arr[idx],arr,dp);
    return dp[idx][target] = pick||notPick;
}
bool subsetSumToK(int n, int k, vector<int>& arr){
    int idx = n-1;
    int target = k;
    vector<vector<bool>>dp(n,vector<bool>(2,-1));
    // Here Idx goes to n-1 & target = true or false, so 2
    f(idx, target, arr,dp);
}*/

// Tabulation 
/*
bool subsetSumToK(int n, int k, vector<int>& arr){
    vector<vector<bool>>dp(n,vector<bool>(k+1,0));// it has 0 to k elements = k+1 elemnts
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    // Base case: If the first element of 'arr' is less than or equal to 'k', set dp[0][arr[0]] to true
    if (arr[0] <= k) {
        dp[0][arr[0]] = true;
    }

    // i = 0, & target = 1 already committed
    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target <= k; target++)
        {
                bool notPick = dp[i-1][target];
                bool pick = false;
                if(target >= arr[i]) pick = dp[i-1][target] - arr[i];
                dp[i][target] = pick || notPick;
        }

    }
    return dp[n-1][k];
}*/
// Space optimisation
bool subsetSumToK(int n, int k, vector<int>&arr){
    vector<bool> prev(k+1,false), curr(k+1, false);// every array has k+1 cols
    prev[0] = curr[0] = true;// first ele = 0
    if (arr[0] <= k) {
        prev[arr[0]] = true;
    }
    
    for (int i = 1; i < n; i++)
    {
        
        for (int target = 1; target <= k ; target++)
        {
                bool notPick = prev[target];
                bool pick = false;
                if(target >= arr[i]) pick = prev[target] - arr[i];
                curr[target] = pick || notPick;// dp[i] = curr & dp[i-1] = prev
        }
        prev = curr;
    }
    return prev[k];
} 
int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();

    // Call the subsetSumToK function and print the result
    if (subsetSumToK(n, k, arr))
        cout << "Subset with the given target found";
    else
        cout << "Subset with the given target not found";
    return 0;
}