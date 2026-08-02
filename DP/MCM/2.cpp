#include<bits/stdc++.h>
using namespace std;
    int t[102][102]; 
    int solve(int i, int j,vector<int>& cuts){
        if(j - i <= 1) return 0;
        if(t[i][j] != -1) return t[i][j];
        int res = 1e9;
        for(int k = i+1; k <= j - 1;k++){
            int cost = (cuts[j] - cuts[i])+solve(i,k,cuts)+solve(k,j,cuts);
            res = min(res,cost);
        }
        return t[i][j] = res;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        memset(t,-1,sizeof(t));
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        return solve(0,cuts.size()-1,cuts);
    }
    // bottom up
    int minCostBottomUp(int n, vector<int>& cuts) {
        
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        int m = cuts.size();
        vector<vector<int>> dp(m,vector<int>(m,0));
        for(int i = m-1; i >= 0; i--){
            for(int j = i+1; j < m; j++){// j = i+1
                if(j - i <= 1) continue;
                int res = 1e9;
                for(int k = i+1; k <= j - 1;k++){
                    int cost = (cuts[j] - cuts[i])+dp[i][k]+dp[k][j];
                    res = min(res,cost);
                }
                dp[i][j] = res;
            }
        }
        return dp[0][m-1];
    }

int main()
{
    int n = 7;
    vector<int> cuts = {1,3,4,5};
    cout << minCost(n, cuts) << endl;
    return 0;
}