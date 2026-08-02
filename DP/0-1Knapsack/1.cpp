#include<bits/stdc++.h>
using namespace std;
/*
int t[1001][1001];
    int solve(int n, int W, vector<int>& val, vector<int>& wt) {
        if(n <= 0 || W == 0)
            return 0;
        
        if(t[n][W] != -1) {
            return t[n][W];
        }
        int take = 0;
        int skip = 0;
        
        //take
        if(wt[n-1] <= W) {
            take = val[n-1] + solve(n-1, W - wt[n-1], val, wt);
        }
        
        skip = solve(n-1, W, val, wt);
        
        return t[n][W] = max(take, skip);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        memset(t, -1, sizeof(t));
        return solve(n, W, val, wt);
        
    }
*/
/*
// Bottom up
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        
        vector<vector<int>> t(n+1, vector<int>(W+1, 0));
        //t[i][j] = max profit with i items and j knapsack weight
        //return t[n][W];
        
        //Base case : if(n == 0 ) return 0; //no item
        for(int j = 0; j < W+1; j++) {
            t[0][j] = 0;
        }
        
        //Base case : if(W == 0) return 0; //knapsack full
        for(int i = 0; i < n+1; i++) {
            t[i][0] = 0;
        }
        
        
        for(int i = 1; i < n+1; i++) {
            for(int j = 1; j < W+1; j++) {
                
                int take = 0;
                int skip = 0;
                
                //take
                if(wt[i-1] <= j) {
                    take = val[i-1] + t[i-1][j - wt[i-1]];//val[i-1] + solve(i-1, j - wt[i-1], val, wt);
                }
                
                skip    = t[i-1][j]; //solve(i-1, j, val, wt);
                
                t[i][j] = max(take, skip); //return t[n][W] = max(take, skip);
                
            }
        }
        
        return t[n][W];
    }
*/
int main()
{
    return 0;
}