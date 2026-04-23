#include<bits/stdc++.h>
using namespace std;
vector<int>LPS(string p){
    int len = 0;
    int i = 1, m = p.length();
    vector<int> ans(m);
    while (i < m)
    {
        if(p[i] == p[len]){
            len++;
            ans[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = ans[len - 1];
            }
            else
            {
                ans[i] = 0;
                i++;
            }
            
            
        }
    } 
    return ans;

}

void kmp(string txt, string pattern){
    vector<int>lps = LPS(pattern);
    int n = txt.size(), m = pattern.length();
    int i = 0, j = 0;
    bool flag = false;
    while (i<n)
    {
        if (txt[i] == pattern[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            cout<<"Pattern found at index : "<<(i-j)<<endl;
            flag = true;
            j = lps[j-1];// If we don't give it
            // Then if txt = "AAAAA", pattern "AAA", then the answers are 0 1 2 
            // So we don't get those
        }
        else if (pattern[j] != txt[i])
        {
            // If already j = 0
            if(j!=0) j = lps[j-1];// send it back to the index where it has to be

            else i++;
        }
        
    }

    if(!flag) cout<<"Not found"<<endl;
}
int main()
{
    string txt = "AAAAA";
    string pattern = "AAA";
    kmp(txt,pattern);

    return 0;
}