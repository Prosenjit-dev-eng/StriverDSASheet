#include<bits/stdc++.h>
using namespace std;
int minimum(vector<int>& v, int n){
    int low = 0, high = n - 1;
    int mini = INT_MAX;
    while (low<=high)
    {
        int mid = low + (high-low)/2;
        // If it sorted already
        if(v[low]<=v[high]){
            mini = min(mini,v[low]);
            break;
        }
        // We have to search the sorted portion
        // Left sorted
        if (v[low] <= v[mid])
        {
            mini = min(v[low],mini);
            low = mid+1;
        }
        // Right sorted
        else 
        {
         mini = min(mini,v[mid]);
         high = mid - 1;
        }
    }
    return mini;
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

    cout<<minimum(v,n)<<endl;
    return 0;
}