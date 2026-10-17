#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        if(a % b == 0) cout<<0<<endl;
        else if(a > b){
            int q = a/b;
            cout<<((q+1)*b - a)<<endl;
        }
        else cout<<(b-a)<<endl;
    }
    return 0;
}