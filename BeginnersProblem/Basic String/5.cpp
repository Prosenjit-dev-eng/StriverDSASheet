#include<bits/stdc++.h>
using namespace std;
bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        int m = s.size();
        map<char,char>s_to_t;
        map<char,char>t_to_s;
        for(int i = 0; i < m; i++){
            char ch1 = s[i];
            char ch2 = t[i];
            if((s_to_t.find(ch1)!=s_to_t.end() && s_to_t[ch1]!=ch2) || (t_to_s.find(ch2)!=t_to_s.end() && 
            t_to_s[ch2]!=ch1)){
                return false;
            }
            s_to_t[ch1] = ch2;
            t_to_s[ch2] = ch1;
        }
        return true;
}

int main()
{
    string s = "egg";
    string t = "itt";
    cout<<isIsomorphic(s,t)<<endl;
    return 0;
}