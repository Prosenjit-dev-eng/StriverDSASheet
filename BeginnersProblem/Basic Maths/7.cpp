#include<bits/stdc++.h>
using namespace std;
int cntDigits(int n)
{
    int cnt=0;
    while(n>0)
    {
        cnt++;
        n/=10;
    }
    return cnt;
}
bool isArmstrong(int n) {
    int temp = n;
    int sum = 0;
    int k = cntDigits(n);
    while(n != 0){
        int d = n%10;
        // Added round() to prevent C++ floating-point truncation errors from pow()
        sum += round(pow(d,k));
        n/=10;
    }
    return sum == temp;
}
int main()
{
    cout<<isArmstrong(153)<<endl;
    return 0;
}