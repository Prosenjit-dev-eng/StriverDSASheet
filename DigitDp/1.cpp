#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
ll dp[20][2][20];// index, tight, count of digits
int solve(string& s, int idx, bool tight, int cnt)
{
    if(idx == s.size()) return cnt;
    if(dp[idx][tight][cnt] != -1) return dp[idx][tight][cnt];
    ll limit = (tight == 1 ? s[idx] - '0' : 9);
    // Now check at that particular index, we can put which digits
    ll ans = 0;
    for (int i = 0; i <= limit; i++)
    {
        // We want to count how many 1's in a number
        int updateCnt = cnt + (i==1 ? 1 : 0);
        ans += solve(s,idx+1,(tight & (i == limit)),updateCnt);
    }
    return dp[idx][tight][cnt] = ans;
}
int main()
{
    ll l,r;
    cin>>l>>r;
    string right = to_string(r);
    memset(dp,-1,sizeof(dp));
    ll rightAns = solve(right,0,1,0);//here ri,index,tight, count
    memset(dp,-1,sizeof(dp));
    string left = to_string(l);
    ll leftAns = solve(left,0,1,0);
    cout<<(rightAns - leftAns)<<endl;
    return 0;
}