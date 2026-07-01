#include<bits/stdc++.h>
using namespace std;
string countAndSay(int n) {
        if(n == 1) return "1";
        string say = countAndSay(n-1);
        string res = "";
        for(int i = 0; i < say.size();){
            int cnt = 0;
            char ch = say[i];
            while(i < say.size() && say[i] == ch){
                cnt++;
                i++;
            }
            res += to_string(cnt);
            res += ch;
        }
    return res;
}
int main()
{
    cout<<countAndSay(4)<<endl;
    return 0;
}