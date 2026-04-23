#include<bits/stdc++.h>
using namespace std;
bool binary_search(vector<int>&v, int n, int x){
    int low = 0, high = n - 1;
    int ans = 0; 
    while (low<=high)
    {
        int mid = (low+high)/2;
        if(v[mid] == x){
            return true;
        }
        else if(x>v[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}
bool element(vector<vector<int>>&mat,int n,int m, int target){

    for (int i = 0; i < n; i++)
    {
        if(mat[i][0]<=target && target<=mat[i][m-1])
        {
            // Let it be a 1-D array
           return binary_search(mat[i],m,target);
        }
        
    }
    return false;
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
    int x;
    cin>>x;
    cout<<element(v,n,m,x)<<endl;
    return 0;
}