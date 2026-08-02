#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin>>n;

    ll cnt = 0;
    vector<ll>p1m,p2m,p1f,p2f;// p1 stores small & p2 stores taller heights
    for (int i = 0; i < n; i++)
    {
        ll y; cin >> y;
        if(y < 0) p1m.push_back(llabs(y));
        else p2m.push_back(y);
    }
    for (int i = 0; i < n; i++)
    {
        ll y; cin >> y;
        if(y < 0) p1f.push_back(llabs(y));
        else p2f.push_back(y);
    }

    if(p1m.size() > 0) sort(p1m.begin(),p1m.end());
    if(p2m.size() > 0) sort(p2m.begin(),p2m.end());
    if(p1f.size() > 0) sort(p1f.begin(),p1f.end());
    if(p2m.size() > 0) sort(p2f.begin(),p2f.end());

    ll i = 0, j = 0;
    while (i < (ll)p1f.size() && j < (ll)p2m.size())
    {
        if(p2m[j] < p1f[i]){ cnt++;i++;j++;}
        else i++;
    }
     i = 0, j = 0;
    while (i < p1m.size() && j < p2f.size())
    {
        if(p1m[j] < p2f[i]) {cnt++;i++;j++;}
        else i++;
    }

    cout<<cnt<<"";

    return 0;
}