#include<bits/stdc++.h>
using namespace std;
    long long ncr(int n, int r){
        long long res = 1;
        if(r > n - r) r = n - r;
        for(int i = 0; i < r; i++){
            res *= (n - i);
            res /= (i+1);
        } 
        return res;
    }
    vector<int> getRow(int rowIndex) {
        vector<int>ans(rowIndex+1);
        for(int i = 0; i <= rowIndex; i++){
            ans[i] = (int) ncr(rowIndex,i);
        }
        return ans;
    }
int main()
{
    
    return 0;
}