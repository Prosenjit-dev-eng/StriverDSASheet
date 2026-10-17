#include<bits/stdc++.h>
using namespace std;
int upperbound(vector<int> &arr, int n, int x, int low, int high){
    int mid  = low + (high - low)/2;
    
    // Basecase
    if(low>high) return -1;
    if(arr[mid] > x) return mid;
    else return upperbound(arr,n,x,mid+1,high);
    
}
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    int x;
    cin>>x;

    cout<<upperbound(v,n,x,0,n-1)<<endl;
    return 0;
}