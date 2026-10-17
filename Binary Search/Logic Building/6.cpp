#include<bits/stdc++.h>
using namespace std;
int lastOccurence(vector<int>&v,int n,int x){
    int low = 0, high = n-1;
    int ans = 0;
    while (low<=high)
    {
        int mid  = low + (high - low)/2;

        if(v[mid]==x){
            ans = mid;
            low = mid + 1;
        }
        else if (v[mid]<x)
        {
            low = mid+1;
        }
        else high = mid - 1;
    }
    if(ans) return ans;
    return -1;
}
int firstOccurence(vector<int>&v,int n,int x){
    int low = 0, high = n-1;
    int ans = 0;
    while (low<=high)
    {
        int mid  = low + (high - low)/2;

        if(v[mid]==x){
            ans = mid;
            high = mid - 1;
        }
        else if (v[mid]<x)
        {
            low = mid+1;
        }
        else high = mid - 1;
    }
    if(ans) return ans;
    return -1;
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
    cout<<firstOccurence(v,n,x)<<endl;
    cout<<lastOccurence(v,n,x)<<endl;
    return 0;
}