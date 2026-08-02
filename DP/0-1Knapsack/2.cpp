//Lc-2742
#include<bits/stdc++.h>
using namespace std;
/*int n;
int t[501][501];
int solve(int i, int walls, vector<int>& cost, vector<int>& time){
    if(walls <= 0) return 0;
    if(i == n) return 1e9;
    if(t[i][walls] != -1) return t[i][walls];
    int take = cost[i] + solve(i+1,walls - 1 - time[i], cost, time);
    int skip = solve(i+1,walls,cost,time);
    return t[i][walls] = min(take,skip);

}
int paintWalls(vector<int>& cost, vector<int>& time) {
    n = cost.size();
    memset(t,-1,sizeof(t));
    return solve(0,n,cost, time);
}*/
int paintWalls(vector<int>& cost, vector<int>& time) {
    int n = cost.size();
    vector<vector<int>>t(n+1,vector<int>(n+1,0));
    for(int i = 0; i < n+1; i++) t[i][0] = 0;
    for(int walls = 1; walls < n + 1; walls++) t[0][walls] = 1e9;
    for(int i = 1; i < n+1; i++){
        for (int j = 1; j < n+1; j++)
        {
            int remaining = max(0, j - 1 - time[i-1]);
            int take = cost[i - 1] + t[i-1][remaining];
            int skip = t[i-1][j];
            t[i][j] = min(take,skip);
        }
        
    }
    return t[n][n];
}
int main()
{
    return 0;
}