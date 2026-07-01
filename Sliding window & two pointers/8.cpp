#include<bits/stdc++.h>
using namespace std;
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        int i = 0, j = 0;
        vector<int>mp(3,0);
        while(j < n){
            char ch = s[j];
            mp[ch - 'a']++;
            while(mp[0] > 0 && mp[1] > 0 && mp[2] > 0){
                cnt += n - j;
                mp[s[i]-'a']--;
                i++;
            }
            j++; 
        }
        return cnt;
    }
int main()
{
    cout<<numberOfSubstrings("aaabc")<<endl;
    return 0;
}