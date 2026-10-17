#include<bits/stdc++.h>
using namespace std;
int insertAtPosition(vector<int>&arr, int n, int x){
    int low = 0, high = n-1;
    int ans = 0;
    while(low<=high){
        int mid  = low + (high - low)/2;
        if(arr[mid]>=x){
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        } 
        else
        {
            low = mid + 1;// look on the right
        }
        
    }
    return ans;
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
    cout<<insertAtPosition(v,n,x)<<endl;
    return 0;
}