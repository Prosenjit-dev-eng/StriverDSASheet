#include<bits/stdc++.h>
using namespace std;
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = (m*n) - 1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(matrix[mid/n][mid%n] > target) r = mid - 1;
            else if(matrix[mid/n][mid%n] < target) l = mid+1;
            else return true;
        }
        return false;
    }
int main()
{
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int x = 3;
    cout<<searchMatrix(matrix,x)<<endl;
    return 0;
}