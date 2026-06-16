#include<bits/stdc++.h>
using namespace std;
bool f(string& s, int i, int cnt,vector<vector<int>>& dp){
        if(cnt < 0) return false;
        if(i == s.size() ) return cnt == 0;
        if(dp[i][cnt] != -1) return dp[i][cnt];
        bool ans;
        if(s[i] == '(') ans = f(s,i+1,cnt+1,dp);
        else if(s[i] == ')') ans = f(s,i+1,cnt-1,dp); 
        else ans =  f(s,i+1,cnt+1,dp) || f(s,i+1,cnt-1,dp) || f(s,i+1,cnt,dp);// for '*'
        return dp[i][cnt] = ans;
}
bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));// coz index and cnt changes
        return f(s,0,0,dp);
}
int main()
{
    cout<<checkValidString("(*))")<<endl;
    return 0;
}