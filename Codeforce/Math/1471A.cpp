#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int x,n;
        cin>>n>>x;
        vector<int>v(n);
        int mini = 0, maxi = 0;
        for(int i = 0; i < n; i++){
            cin>>v[i];
            maxi += ceil(v[i]/x);
            mini += v[i];
        }
        mini = ceil(mini/x);
        cout<<mini<<" "<<maxi<<endl;
    }
    return 0;
}