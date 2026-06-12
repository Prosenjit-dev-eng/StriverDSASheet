#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; // Number of test cases
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int>v(n);
        for (int i = 0; i < n-1; i++)
        {
            cin>>v[i];
        }
        int s = accumulate(v.begin(),v.end(),0);
        cout<<(-s)<<endl;
        
    }
    return 0;
}