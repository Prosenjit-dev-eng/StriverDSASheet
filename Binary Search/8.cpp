#include<bits/stdc++.h>
using namespace std;
int findEleInRotatedSortedDuplicateArray(vector<int>& v, int n, int x){
    int low = 0, high = n - 1;
    while (low<=high)
    {
        int mid = low + (high-low)/2;
        if(v[mid] == x) return 1;
        // Edge case
        if(v[low] == v[mid] == v[high]){
            low++;
            high--;
            continue;
        }
        // We have to search the sorted portion
        // Left sorted
        if (v[low] <= v[mid])
        {
            if(v[low]<=x && v[mid]>=x) high = mid - 1;
            else low = mid + 1;
        }
        // Right sorted
        else 
        {
            if(v[mid]<=x && v[high]>=x) low = mid + 1;
            else high = mid - 1;
        }
    }
    return 0;
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
    cout<<findEleInRotatedSortedDuplicateArray(v,n,x)<<endl;
    return 0;
}