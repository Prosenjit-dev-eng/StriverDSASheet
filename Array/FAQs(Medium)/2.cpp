#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int binocoeff(int n, int r){
        long long res = 1;
        if(r > n - r) r = n - r;
        for(int i = 0; i < r; i++){
            res *= (n - i);
            res /= (i+1);
        }
        return (int)res;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        for(int i = 0; i < numRows; i++){
            vector<int>row;
            for(int j = 0; j <= i; j++){
                row.push_back(binocoeff(i,j));
            }
            res.push_back(row);
        }
        return res;
    }
};
int main()
{
    return 0;
}