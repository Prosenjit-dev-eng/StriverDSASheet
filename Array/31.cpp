#include<bits/stdc++.h>
using namespace std;


vector<vector<int>>zeroes(vector<vector<int>> &mat, int n, int m){
    // int row[n] = {0},col[m] = {0};
    int col0 = 1;// The col0, which is avobe cliff part of the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(mat[i][j] == 0){
            // mark the ith row
            mat[i][0] = 0;
            // mark the jth column
            if(j!=0)
            mat[0][j] = 0;
            else 
            col0 = 0;

            }
        }
        
    }
    // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
        for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            // check for col & row:
            if(mat[j][0] == 0 || mat[i][0] == 0){
                mat[i][j] = 0;
            }
        }
        
    }
    //step 3: Finally mark the 1st col & then 1st row:
    if(mat[0][0] = 0){
        for (int j = 0; j < m; j++)
        {
            mat[0][j] = 0;
        }
        
    }
    if(col0 == 0){
        for (int i = 0; i < n; i++)
        {
            mat[i][0] = 0;
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