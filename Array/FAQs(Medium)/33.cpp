#include<bits/stdc++.h>
using namespace std;

void spiral(vector<vector<int>> &mat, int n, int m){
    int top = 0, left = 0, right = mat[0].size() - 1,bottom = mat.size()-1;
    int direction = 0;
    while(left<=right && top <= bottom){
        if(direction == 0){
            // left to right
            for (int col = left; col <= right; col++)
            {
                cout<<mat[top][col]<<" ";// bcz here top constant
            }
            top++;//
        }
            else if(direction == 1){
            // top to bottom
            for (int row = top; row <= bottom; row++)
            {
                cout<<mat[row][right]<<" ";
            }
            right--;// 
        }    
        else    if(direction == 2){
            // right to left
            for (int col = right; col >= left; col--)
            {
                cout<<mat[bottom][col]<<" ";
            }
            bottom--;
        }        
        else {
            // bottom to top
            for (int row = bottom; row >= top; row--)
            {
                cout<<mat[row][left]<<" ";
            }
            left++;
        }
        direction = (direction+1)%4;
    }

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
    spiral(mat,n,m);
    
    return 0;
}