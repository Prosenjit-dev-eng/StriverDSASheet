#include<bits/stdc++.h>
using namespace std;
bool solve(string &s, int i, int j){
    if(i >= j) return true;
    if(s[i] == s[j]) solve(s,i+1,j-1);
    else return false;
}
string longestPalindrome(string &s){
    int n = s.size();
    int longest = 0;
    int sp = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if(solve(s,i,j)){
                if (j - i + 1 > longest)
                {
                    longest = j - i + 1;
                    sp = i;
                }
                
            }
        }
        
    }
    return s.substr(sp,longest);
    
}
int main()
{
    return 0;
}