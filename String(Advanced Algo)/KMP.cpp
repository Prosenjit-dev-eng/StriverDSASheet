#include<bits/stdc++.h>
using namespace std;
void findLps(vector<int>& lps, string s){
    int n = s.size();
    int prefix = 0, suffix = 1;
    while (suffix < n)
    {
        if (s[prefix] == s[suffix])
        {
            lps[suffix] = prefix+1;
            suffix++;
            prefix++;
        }
        else
        {
            if (prefix == 0)
            {
                lps[suffix] = 0;
                suffix++;
            }
            else
            {
                prefix = lps[prefix-1];
            }
            
        }
        
    }
    
}
int strStr(string haystack, string needle) {
    int n = haystack.size(), m = needle.size();
    vector<int>lps(m,0);
    findLps(lps,needle);
    int first = 0, second = 0;
    while (first < n  && second < m)
    {
        if (haystack[first] == needle[second])
        {
            first++;
            second++;
        }
        else
        {
            if (second == 0)
            {
                first++;
            }
            else second = lps[second - 1];
            
        }
        
    }
    return second == m ? first - second : -1;
}
int main()
{
    cout<<strStr("leetcode","leeto")<<endl;
    return 0;
}