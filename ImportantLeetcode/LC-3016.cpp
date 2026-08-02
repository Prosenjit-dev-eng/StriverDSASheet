#include<bits/stdc++.h>
using namespace std;

    int minimumPushes(string word) {
        int n = word.size();
        vector<int>mp(26,0);
        for(char ch : word){
            mp[ch-'a']++;
        }
        sort(mp.begin(),mp.end(),greater<int>());
        int res = 0;
        for(int i = 0; i < 26;i++){
            int freq = mp[i];
            int press = i/8+1;
            res += freq*press;
        }
        return res;
    }
int main()
{
    string word = "xyzxyzxyz";
    cout<<minimumPushes(word)<<endl;
    return 0;
}