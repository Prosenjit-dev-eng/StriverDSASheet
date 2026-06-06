#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int>v(n);
        for (int i = 0; i < n; i++)
        {
            cin>>v[i];
        }
        bool sorted = true;
        if(k>1){
            cout<<"YES"<<endl;
            continue;
        }
        else
        {
            for (int i = 1; i < n; i++)
            {
                if(v[i] < v[i-1]){
                    sorted = false;
                    break;
                }
            }
            
        }
        (sorted ? cout << "YES" <<endl : cout<<"NO"<<endl);  
        
    }
    return 0;
}