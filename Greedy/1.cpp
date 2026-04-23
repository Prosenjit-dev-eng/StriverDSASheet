#include<bits/stdc++.h>
using namespace std;
int maxAssignCookies(vector<int>g,vector<int>s){
    sort(g.begin(),g.end());// greed of children
    sort(s.begin(),s.end());// size of cookies
    int n = g.size(), m = s.size();
    int l = 0, r = 0,cnt = 0;
    // l is traversing over the s
    while (l<m)
    {
        if(s[l]>=g[r]){
            cnt++;
            r++;
        }
        l++;
    }
    return cnt;
}
int main()
{
    vector<int>g = {1,5,3,3,4};
    vector<int>s = {4,2,1,2,1,3};
    cout<<maxAssignCookies(g,s)<<endl;
    return 0;
}