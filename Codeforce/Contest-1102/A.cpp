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
        vector<ll>v(n);
        for (int i = 0; i < n; i++)
        {
            cin>>v[i];
        }
        sort(v.rbegin(),v.rend());
        bool flag = true;
        if(v.size() > 2){
            for (int i = 2; i < n; i++)
            {
                if((v[i-2] % v[i-1]) != v[i]){
                    flag = false;
                    break;
                }
            }
            
        }
        if(!flag) cout<<-1<<endl;
        else cout<<v[0]<<" "<<v[1]<<endl;
        
    }
    
    return 0;
}