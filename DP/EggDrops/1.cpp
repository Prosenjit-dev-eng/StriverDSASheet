#include<bits/stdc++.h>
using namespace std;
// Lc-1884
/*int solve(int eggs, int floors) {

    // Base cases
    if (floors == 0 || floors == 1)
        return floors;

    if (eggs == 1)
        return floors;

    int ans = INT_MAX;

    for (int x = 1; x <= floors; x++) {

        int breakCase = solve(eggs - 1, x - 1);

        int notBreakCase = solve(eggs, floors - x);

        int attempts = 1 + max(breakCase, notBreakCase);

        ans = min(ans, attempts);
    }

    return ans;
}*/
int solve(int floors, int eggs){
    vector<vector<int>>dp(floors+1,vector<int>(eggs+1,0));
    // If the floor == 1, then it always
    for(int e = 1; e <= eggs; e++){
        dp[1][e] = 1; 
    }
    // if the eggs == 1, we should check every floors
    for(int f = 1; f <= floors; f++){
        dp[f][1] = f; 
    }

    for (int f = 2; f <= floors; f++)
    {
        for(int e = 2; e <= eggs; e++){
            dp[f][e] = INT_MAX;
            for (int x = 1; x <= f; x++)
            {
                int breakCase = dp[x - 1][e - 1];// break => floor o egg kombe
                int notBreakCase = dp[f - x][e];// floor barbe egg same thakbe
                int attempts = 1 + max(breakCase,notBreakCase);

                dp[f][e] = min(dp[f][e],attempts);
            }
            
        }
    }
    return dp[floors][eggs];
    
}
int twoEggDrop(int n) {
    return solve(n,2);   
}
int main()
{
    cout<<twoEggDrop(100)<<endl;
    return 0;
}