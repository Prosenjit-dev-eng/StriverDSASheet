#include<bits/stdc++.h>
// Using dp to create fibonacci series
using namespace std;
// Dp has always 4 parts

// Basic
/*int fib(int n){
    if(n<=1) return n;
    return fib(n-1)+fib(n-2);
}*/ 
// T.C. -> T(n) = O(2^n)

// Memoisation
// int fib(int n, vector<int>&dp){
//     if (n <= 1)
//         return n;
//     // If value already computed, return it
//     if (dp[n] != -1)
//         return dp[n];

//     // Otherwise compute and store it
//     return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
// }
// T.C.= o(n), S.C. = o(n)


// Tabulation
// int fib(int n) {
//     if (n <= 1)
//         return n;

//     vector<int> dp(n + 1);
//     dp[0] = 0;
//     dp[1] = 1;

//     for (int i = 2; i <= n; i++) {
//         dp[i] = dp[i - 1] + dp[i - 2];
//     }

//     return dp[n];
// }
// T.C.= o(n), S.C. = o(n)

// Optimized version using memoization
int main()
{
    int n;
    cin >> n;
    // vector<int> dp(n + 1, -1);
    // cout << fib(n, dp) << endl;
    int prev2 = 0, prev1 = 1;
    for (int i = 2; i <= n; i++)
    {
        int curri = prev1 + prev2;
        prev2 = prev1;
        prev1 = curri;
    }
    cout<<prev1 << endl; // Output the nth Fibonacci number
    return 0;
}