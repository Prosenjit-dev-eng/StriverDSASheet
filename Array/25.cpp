#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Next permutation
vector<int>permutation(vector<int> &a,int n){
    int idx = -1;
    // To find last dip
    for (int i = n - 2; i >= 0; i--)
    {
        if(a[i]<a[i+1]){
            idx = i;
            break;
        }
    }
    if(idx == -1){ reverse(a.begin(),a.end());
        return a;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if(a[i]>a[idx]){
            swap(a[i],a[idx]);
            break;
        }
    }
    reverse(a.begin()+idx+1, a.end());
    return a;
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    vector<int>ans = permutation(v,n);
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }
    
    return 0;
}