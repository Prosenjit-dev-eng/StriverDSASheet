#include<iostream>
#include<string>
using namespace std;
bool isPalindrome(string s,int i,int n){
    if(i>=n/2) return true;
    if(tolower (s[i]) != tolower (s[n-i-1])) return false;// tolower use to lower case
    return isPalindrome(s, i+1, n);
}
int main()
{
    string s = "Madam";
    int n = s.length();
    cout<<isPalindrome(s,0,n)<<endl;    
    return 0;
}