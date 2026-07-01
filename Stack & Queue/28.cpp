#include<bits/stdc++.h>
using namespace std;
int celebrity(vector<vector<int>>& mat) {
    int n = mat.size();
    int top = 0, down = n - 1;
    while (top < down)
    {
        if (mat[top][down])
        {
            top++;
        }
        else if(mat[down][top]) down--;
        else{
            top++;
            down--;
        }
        
    }
    if(top > down) return -1;
    for (int i = 0; i < n; i++)
    {
        if(i == top) continue;
        if(mat[top][i] == 1 || mat[i][top] == 0) return -1;
    }
    return top;
}
int main()
{
    vector<vector<int>> mat = {
                {1, 1, 0},
                {0, 1, 0},
                {0, 1, 1}
    };
    cout<<celebrity(mat)<<endl;
    return 0;
}