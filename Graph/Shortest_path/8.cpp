#include<bits/stdc++.h>
using namespace std;
void floydwarshall(vector<vector<int>>&matrix){
    int n = matrix.size();
    for(int via = 0; via < n; via++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(i == j) matrix[i][j] = 0;
                if (matrix[i][via] != INT_MAX && matrix[via][j] != INT_MAX) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
        }
    }
}
int main()
{
    return 0;
}