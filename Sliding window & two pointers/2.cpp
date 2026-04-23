#include<bits/stdc++.h>
using namespace std;
int len(string s){
    int l = 0, r = 0;
    int n = s.size();
    vector<int>hash(256,-1);
    int maxlen = 0;
    while (r<n)
    {
        if (hash[s[r]]!=-1)
        {
            if(hash[s[r]]>=l){
                l = hash[s[r]]+1;
            }
        }
        maxlen = max(maxlen,r-l+1);
        hash[s[r]] = r; 
        r++;
    }
    return maxlen;
}
int main()
{
    string s = "abcabcbb";
    cout<<len(s)<<endl;
    return 0;
}