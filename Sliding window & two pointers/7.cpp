#include<bits/stdc++.h>
using namespace std;
    string minWindow(string s, string t) {
        // Ex: "ddaaabbca"
        int s_idx = -1, minlen = INT_MAX;
        int n = s.size(), m = t.size();
        int hash[256] = {0};
        // Hash table
        for(int i = 0; i < m; i++){
            hash[t[i]]++;
        }
        int cnt = 0;
        int r = 0, l = 0;
        while(r < n){
            // If the hash table value positive, we increment only cnt
            if(hash[s[r]]>0){
                cnt++;
            }
            hash[s[r]]--;
            r++;
            
        // Now l = d (at 0 th position) & r = c (at 7 th position)
        while(cnt == m){
            if((r-l) < minlen){
                minlen = (r-l);
                s_idx = l;
            }
            hash[s[l]]++;
            // Now i cutdown cnt if hash[s[l]]>0
            if(hash[s[l]]>0){
                cnt--;
            }
            l++;
         }
        }
    return (s_idx == -1) ? "" : s.substr(s_idx, minlen);
    }
int main(){
    string s = "ddaaabbbca";
    string t = "abc";
    cout<<minWindow(s,t)<<endl;
    return 0;
}