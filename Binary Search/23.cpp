#include<bits/stdc++.h>
using namespace std;
int firstOccurence(vector<int>&v,int n,int x){
    int low = 0, high = n-1;
    int ans = -1;
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
    return ans;
}
int maxidx(vector<vector<int>>&mat,int n, int m){
    int max_cnt = 0;
    int idx  = -1;
    for (int i = 0; i < n; i++)
    {
        // We can optimise it by binary search
       /* for (int j = 0; j < m; j++)
        {
            count += mat[i][j];
        }*/
       int first_one = firstOccurence(mat[i],m,1);
       int count = (first_one == -1) ? 0 : (m - first_one);
        if(count > max_cnt){
            max_cnt = count;
            idx = i;
        }
        
    }
    return idx;
}
int main()
{
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>>v(n,vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>v[i][j];
        }
        
    }
    cout<<maxidx(v,n,m)<<endl;
    return 0;
}