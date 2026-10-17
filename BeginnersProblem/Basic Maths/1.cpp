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
int main()
{
    int n;
    cin>>n;
    cout<<cntDigits(n)<<endl;
    return 0;
}