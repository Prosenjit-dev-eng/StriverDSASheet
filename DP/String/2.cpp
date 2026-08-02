#include<bits/stdc++.h>
using namespace std;
int solve(int i, int j, string word1, string word2){
    
    if(i == word1.size()) return word2.size() - j;//insert
    if(j == word2.size()) return word1.size() - i;// delete
    if(word1[i] == word2[j]) return solve(i+1,j+1,word1,word2);
    int replace = 1+solve(i+1,j+1,word1,word2);
    int intsert = 1+solve(i,j+1,word1,word2);
    int del = 1+solve(i+1,j,word1,word2);
    return min(replace,min(del,intsert));
}
int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0) dp[i][j] = m+n;
            if(word1[i - 1] == word2[j-1]) return dp[i][j] = dp[i-1][j-1];
            int replace = 1+dp[i-1][j-1];
            int intsert = 1+dp[i][j-1];
            int del = 1+dp[i-1][j];
            dp[i][j] = min(replace,min(del,intsert));
  
        }
        
    }
    return dp[m][n];    
}
int main()
{
    return 0;
}