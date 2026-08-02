#include<bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int row = 0, col = n - 1;// Top - right
    while(row < m && col >= 0){
        if(matrix[row][col] < target) row++;
        else if(matrix[row][col]  > target) col--;
        else return true;
    }
    return false;
}
int main()
{
    vector<vector<int>>matrix = {{1,4},{2,5}};
    cout<<searchMatrix(matrix,2)<<endl;
    return 0;
}