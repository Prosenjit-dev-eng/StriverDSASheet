#include<bits/stdc++.h>
using namespace std;
int len(string s, int k){
    int n = s.length();
    int  l = 0,r = 0, maxlen = 0, cnt = 0;
    while (r<n)
    {
        if(s[l]!=s[r]) cnt++;
        if(cnt>k){
            if(s[l]==s[r]) cnt--;
            l++;   
        } 
        
        if (cnt<=2)
        {
            maxlen = (maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
    
}
int main()
{
    string s = "ABBA";
    int k = 2;
    cout<<len(s,k)<<endl;
    return 0;
}