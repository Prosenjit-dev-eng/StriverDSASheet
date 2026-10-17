#include<bits/stdc++.h>
using namespace std;


vector<vector<int>>zeroes(vector<vector<int>> &mat, int n, int m){
    int row[n] = {0},col[m] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(mat[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
        
    }
        for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(row[i] || col[j]){
                mat[i][j] = 0;
            }
        }
        
    }
    return mat;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>mat(n,vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>mat[i][j];
        }
        
    }
    vector<vector<int>>ans = zeroes(mat,n,m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}