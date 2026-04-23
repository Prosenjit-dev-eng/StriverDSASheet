#include<bits/stdc++.h>
using namespace std;
int rotatedTimes(vector<int>& v, int n){
    int low = 0, high = n - 1;
    int mini = INT_MAX;
    int idx = -1;
    while (low<=high)
    {
        int mid = low + (high-low)/2;
        // If it sorted already
        if(v[low]<=v[high]){
            if(v[low]<mini){
                idx = low;
                mini = v[low];
            }
            break;
        }
        // We have to search the sorted portion
        // Left sorted
        if (v[low] <= v[mid])
        {
            // mini = min(v[low],mini);just do it manually
                if(v[low]<mini){
                idx = low;
                mini = v[low];
            }
            low = mid+1;
        }
        // Right sorted
        else 
        {
         high = mid - 1;
         if(v[mid]<mini){
            idx = mid;
            mini = v[mid];
         }
        }
    }
    return idx;
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

    cout<<rotatedTimes(v,n)<<endl;
    return 0;
}