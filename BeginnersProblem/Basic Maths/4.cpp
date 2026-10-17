#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(int x) {
    string s = to_string(x);
    int n = s.size();
    for(int i = 0; i < (n/2); i++){
        if(s[i]!=s[n-i-1]) return false;
    }
    return true;
}
int main()
{
    cout<<isPalindrome(121)<<endl;
    return 0;
}