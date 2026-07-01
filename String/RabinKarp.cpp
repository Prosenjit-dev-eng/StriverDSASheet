#include<bits/stdc++.h>
using namespace std;
const int Base = 1000000;
int rabinKarp(string src, string target){
    int s = src.size(), t = target.size();
    if(src == "" || target == "") return -1;
    int power = 1, targetCode = 0;
    for(int i = 0; i < t; i++){
        power = (power*31)%Base;
        targetCode = (targetCode * 31+target[i])%Base;// here target[i] turns into character
    }
    int hashCode = 0;
    for (int i = 0; i < s; i++)
    {
        hashCode = (hashCode * 31 + src[i]) % Base;
        if(i < t - 1) continue;
        if(i >= t) hashCode = (hashCode - src[i-t]*power)%Base;
        
        if(hashCode < 0) hashCode += Base;
        if (hashCode == targetCode)
        {
            if (src.substr(i-t+1,t) == target)
            {
                return i - t + 1;
            }
            
        }
        
    }
    return -1;

}
int repeatedStringMatch(string a, string b) {
    if(a == b) return 1;
    int cnt = 1;
    string src = a;
    while(src.size() < b.size()){
        src += a;
        cnt++;
    }
    if(src == b) return cnt;
    if(rabinKarp(src,b) != -1) return cnt;
    if(rabinKarp(src+a,b) != -1) return cnt+1;
    return -1;
}
int main()
{
    cout<<repeatedStringMatch("aaaab","aab")<<endl;
    return 0;
}