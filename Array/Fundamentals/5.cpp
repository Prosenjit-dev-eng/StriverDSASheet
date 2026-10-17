#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);

    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    
    int k;
    cin>>k;

    k%=n;

    reverse(v.begin(),v.end());// time = o(n)
    reverse(v.begin(),v.begin()+k);// time = o(k)
    reverse(v.begin()+k,v.end());// time = o(n-k)


    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }
    
    return 0;
}