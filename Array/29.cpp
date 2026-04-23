#include<bits/stdc++.h>
using namespace std;

void markI(vector<vector<int>> &mat, int n, int m,int i){
    for (int j = 0; j < m; j++)
    {
        if(mat[i][j] != 0) mat[i][j] = -1;
    }
    
}
void markJ(vector<vector<int>> &mat, int n, int m,int j){
    for (int i = 0; i < n; i++)
    {
        if(mat[i][j] != 0) mat[i][j] = -1;
    }
    
}
vector<vector<int>>zeroes(vector<vector<int>> &mat, int n, int m){
    int row,col;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(mat[i][j] == 0){
                markI(mat,n,m,i);
                markJ(mat,n,m,j);
            }
        }
        
    }
        for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(mat[i][j] == -1){
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