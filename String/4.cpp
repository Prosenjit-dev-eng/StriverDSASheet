#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int myAtoi(string s){
    if(isalpha(s[0])) return 0;//check it be alphabetic character or not
    int l = s.length();
    ll n = 0;
    int i = 0;
    int sign = 1;
    while (s[i] == ' ' && i < l)
    {
        i++; // skip spaces
    }
    if (i < l && (s[i] == '+' || s[i] == '-'))
    { 
        if(s[i] == '-') sign = -1;
        i++;
    }
    while (i < l && isdigit(s[i]))
    {
        n = n*10 + (s[i] - '0');// convert string to integer
        if(n*sign < INT_MIN) return INT_MIN;
        if(n*sign > INT_MAX) return INT_MAX;
        i++;
    }
    return sign*n;
}
int main()
{
    cout<<myAtoi("123")<<endl;
    return 0;
}