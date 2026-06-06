#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,x;
        cin>>n>>x;
        vector<int>v(n);
        for (int i = 0; i < n; i++)
        {
            cin>>v[i];
        }

        int maxi = v[0];
        for (int i = 1; i < n; i++)
        {
            maxi = max(maxi,v[i] - v[i-1]);
        }
        maxi = max(maxi, 2*(x - v[n-1])); 
        
        cout<<maxi<<endl; 
    }
    return 0;
}