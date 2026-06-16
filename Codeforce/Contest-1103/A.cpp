#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int>v(n);
        for (int i = 0; i < n; i++)
        {
            cin>>v[i];
        }
        int mini = *min_element(v.begin(),v.end());
        int maxi = *max_element(v.begin(),v.end());
        cout<<(1+maxi-mini)<<endl;
    }
    
    return 0;
}