// optimise
#include<bits/stdc++.h>
using namespace std;

bool element(vector<vector<int>>&mat,int n,int m, int target){
    int low  = 0, high = n*m - 1;
    while (low<=high)
    {
        int mid = (low+high)/2;
        int row = mid/m;
        int col = mid%m;
        if(mat[row][col] == target) return true;
        else if(mat[row][col] < target) high = mid - 1;
        else low = mid + 1;
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