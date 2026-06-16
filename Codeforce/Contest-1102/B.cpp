#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define pb push_back
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        vl v;
        for (int i = 0; i < 10; i++)
        {
            v.push_back(i);
        }
        v.pb(22);
        v.pb(11);
        ll rem = n%12;// coz n%12 == a%12
        ll a = v[rem];
        if(a <= n) cout<<a<<" "<<(n-a)<<endl;
        else cout<<-1<<endl;
    }
    
    return 0;
}