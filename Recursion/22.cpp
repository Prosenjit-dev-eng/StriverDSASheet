#include<bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
        if (isalpha(s[0])) return 0;
        int l = s.length();
        long long n = 0;
        int i = 0;
        int sign = 1;
        while(s[i] == ' ' && i < l) i++;
        if(i < l && (s[i] == '+' || s[i] == '-')){
            if(s[i] == '-') sign = -1;
            i++;
        }
        while(i < l && isdigit(s[i])){
            n = n*10 + (s[i] - '0');
            if(n*sign < INT_MIN) return INT_MIN;
            if(n*sign > INT_MAX) return INT_MAX;

            i++;
        }

        return sign*n;

    }
int main()
{
    string s = "123";
    cout<<myAtoi(s)<<endl;
    return 0;
}