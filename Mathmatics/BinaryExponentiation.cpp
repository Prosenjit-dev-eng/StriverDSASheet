#include<bits/stdc++.h>
using namespace std;
int binaryExponentiation(int a, int b){
    int ans = 1;
    while (b>0)
    {
        if (b&1)
        {
            // ODD
            ans*=a;
        }
        a*=a;
        b>>=1;
    }
    return ans;
    
}
// Recursively
int binaryExponentiationRec(int a, int b){
    if (b == 0)
    {
        return 1;
    }
    int ans = binaryExponentiationRec(a, b/2);
    ans*=ans;
    if (b%2 == 1)
    {
        ans*=a;
    }
    return ans;
    
}
int main()
{
    int a, b;
    cin>>a>>b;
    cout<<binaryExponentiation(a, b)<<endl;

    return 0;
}