#include<bits/stdc++.h>
using namespace std;
int findPeakIndex(vector<int>& v, int n){
    // Base cases
    if(n == 1) return 0;
    if(v[0]>v[1]) return 0;
    if(v[n-2]<v[n-1]) return n-1;

    int low = 1, high = n - 2;
    while (low<=high)
    {   
        int mid = low + (high-low)/2;

  
        if(v[mid-1]<v[mid] && v[mid]>v[mid+1]) return mid;
        // Left
        if(v[mid]>v[mid-1]){
            low = mid+1;
        }
        // If we are in the right:
        // Or, arr[mid] is a common point:
        else{
            high = mid - 1;
        }

    }
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

    cout<<findPeakIndex(v,n)<<endl;
    return 0;
}