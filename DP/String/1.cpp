#include<bits/stdc++.h>
using namespace std;
// Memoisation
/*int lcsUtil(string& s1, string& s2, int ind1, int ind2, vector<vector<int>>& dp) {
    // Base case: If either string reaches the end, return 0
    if (ind1 < 0 || ind2 < 0)
        return 0;

    // If the result for this pair of indices is already calculated, return it
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    // If the characters at the current indices match, increment the LCS length
    if (s1[ind1] == s2[ind2])
        return dp[ind1][ind2] = 1 + lcsUtil(s1, s2, ind1 - 1, ind2 - 1, dp);
    else
        // If the characters don't match, consider two options: moving either left or up in the strings
        
        return dp[ind1][ind2] = max(lcsUtil(s1, s2, ind1, ind2 - 1, dp), lcsUtil(s1, s2, ind1 - 1, ind2, dp));
}

int lcs(string s1, string s2){
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1)); // Create a DP table
    return lcsUtil(s1, s2, n - 1, m - 1, dp);
} */
// tabulation
// int lcs(string s1, string s2) {
//     int n = s1.size();
//     int m = s2.size();

//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1)); // Create a DP table

//     // Initialize the base cases
//     for (int i = 0; i <= n; i++) {
//         dp[i][0] = 0;// second string is empty
//     }
//     for (int i = 0; i <= m; i++) {
//         dp[0][i] = 0;// first string is emptys
//     }

//     // Fill in the DP table to calculate the length of LCS
//     for (int ind1 = 1; ind1 <= n; ind1++) {// why 1 to n , bcz it goes from n-1 to 0 in recursion, so here, just reverse
//         for (int ind2 = 1; ind2 <= m; ind2++) {
//             if (s1[ind1 - 1] == s2[ind2 - 1])
//                 dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1]; // Characters match, increment LCS length
//             else
//                 dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]); // Characters don't match, consider the maximum from left or above
//         }
//     }

//     return dp[n][m]; // Return the length of the Longest Common Subsequence
//     // not dp[n-1][m-1] bcz here we store dp[0][0] previously
// }
// space opt

int lcs(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();


    // // Initialize the base cases
    // for (int i = 0; i <= n; i++) {
    //     dp[i][0] = 0;// second string is empty
    // }
    // for (int i = 0; i <= m; i++) {
    //     dp[0][i] = 0;// first string is emptys
    // }
    // the base cases are = 0 , so when we initialise the array as zero, it's automatically do the work
    vector<int>prev(m+1,0), curr(m+1,0);// m+1 cols for str2
    // Fill in the DP table to calculate the length of LCS
    for (int ind1 = 1; ind1 <= n; ind1++) {// why 1 to n , bcz it goes from n-1 to 0 in recursion, so here, just reverse
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                curr[ind2] = 1 + prev[ind2 - 1]; // Characters match, increment LCS length
            else
                curr[ind2] = max(prev[ind2], curr[ind2 - 1]); // Characters don't match, consider the maximum from left or above
        }
        prev = curr;
    }

    return prev[m]; // Return the length of the Longest Common Subsequence
    // not dp[n-1][m-1] bcz here we store dp[0][0] previously
}
int main()
{
    string s1 = "acd";
    string s2 = "ced";

    // Call the function to find and output the length of the Longest Common Subsequence
    cout << "The Length of Longest Common Subsequence is " << lcs(s1, s2) << endl;
    
    return 0;
}