#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
// Findpower
ll findPower(int a, int b){
    ll res = 1;
    while (b > 0)
    {
        if (b%2 == 1)
        {
            res = (res*a)%MOD;
        }
        a = (1LL*a*a)%MOD;
        b >>= 1;
    }
    return res;
}
ll fact(int n){
    if(n == 0) return 1;
    return (n*fact(n-1))%MOD;
}
ll modnCr(int n, int r){
    if(r < 0 || r > n) return 0;
    ll a = fact(n)%MOD;
    ll b = fact(n - r) * fact(r)%MOD;
    return a*findPower(b,MOD-2)%MOD; 
}
int main()
{
    int n, r;
    cin>>n>>r;
    cout<<modnCr(n, r)<<endl;
    return 0;
}