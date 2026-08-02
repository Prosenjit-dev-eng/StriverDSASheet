#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k){
    int m = grid.size(), n = grid[0].size();
    int rc = m*n;
    k %= rc;
    auto shift = [&](int i, int j){
        while (i < j)
        {
            swap(grid[i / n][i % n], grid[j / n][j % n]);
                i++;
                j--;
        }
        
    };
    shift(0,n-1);
    shift(0,k-1);
    shift(k,n-1);
    return grid;
}

int main()
{
    return 0;
}