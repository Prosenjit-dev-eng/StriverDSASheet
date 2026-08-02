#include<bits/stdc++.h>
using namespace std;
int n;

    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

        // Base case
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {

                // Not pick
                dp[i][j] = dp[i - 1][j];

                // Pick
                if (j >= coins[i - 1])
                    dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }

        return dp[n][amount];
    }
int main()
{
    vector<int>nums = {1,2,5};
    cout<<change(5,nums)<<endl;
    return 0;
}