#include<bits/stdc++.h>
using namespace std;
// 3D DP
// Maximum chocolates
// Memoization
/*int f(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp)
{
    int n = grid.size();
    int m = grid[0].size();

    // Out of bounds
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return -1e9;

    // Base case: last row
    if (i == n - 1) {
        if (j1 == j2)
            return grid[i][j1];
        else
        // Different columns
        return grid[i][j1] + grid[i][j2];
    }

    // Check if already computed
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    int maxi = -1e9;

    // Explore all 9 possible moves
    for (int dj1 = -1; dj1 <= 1; dj1++) {
        for (int dj2 = -1; dj2 <= 1; dj2++) {
            int value = 0;
            if (j1 == j2)
                value = grid[i][j1];
            else
                value = grid[i][j1] + grid[i][j2];

            value += f(i + 1, j1 + dj1, j2 + dj2, grid, dp);
            maxi = max(maxi, value);
        }
    }

    return dp[i][j1][j2] = maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>>&grid)
{
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return f(0, 0, c-1, grid, dp);
}*/
// Time Complexity: O(N*M*M*9) ~ O(N*M*M), as there are N*M*M states and for each state, we are exploring 9 moves.
// Space Complexity: O(N*M*M) + O(N), for the dp array and recursion
// Tabulation
// Function to find the maximum chocolates that can be collected
/*int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    // Create a 3D DP array to store computed results
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

    // Initialize the DP array for the last row
    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
            if (j1 == j2)
                dp[n - 1][j1][j2] = grid[n - 1][j1];
            else
                dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    // Outer nested loops for traversing the DP array from the second-to-last row up to the first row
    for (int i = n - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                int maxi = 0;

                // Inner nested loops to try out 9 options (diagonal moves)
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        int ans;

                        if (j1 == j2)
                            ans = grid[i][j1];
                        else
                            ans = grid[i][j1] + grid[i][j2];

                        // Check if the move is valid (within the grid boundaries)
                        if ((j1 + di < 0 || j1 + di >= m) || (j2 + dj < 0 || j2 + dj >= m))
                            ans += -1e9; // A very large negative value to represent an invalid move
                        else
                            ans += dp[i + 1][j1 + di][j2 + dj]; // Include the DP result from the next row

                        maxi = max(ans, maxi); // Update the maximum result
                    }
                }
                dp[i][j1][j2] = maxi; // Store the maximum result for this state in the DP array
            }
        }
    }

    // The maximum chocolates that can be collected is stored at the top-left corner of the DP array
    return dp[0][0][m - 1];
}*/
// Space optimisation
int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    // Create a 3D DP array to store computed results
    // vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
    vector<vector<int>> front(m, vector<int>(m, 0));
    vector<vector<int>> curr(m, vector<int>(m, 0));
    // Initialize the DP array for the last row
    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
            if (j1 == j2)
                front[j1][j2] = grid[n - 1][j1];
            else
                front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    // Outer nested loops for traversing the DP array from the second-to-last row up to the first row
    for (int i = n - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                int maxi = 0;

                // Inner nested loops to try out 9 options (diagonal moves)
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        int ans;

                        if (j1 == j2)
                            ans = grid[i][j1];
                        else
                            ans = grid[i][j1] + grid[i][j2];

                        // Check if the move is valid (within the grid boundaries)
                        if ((j1 + di < 0 || j1 + di >= m) || (j2 + dj < 0 || j2 + dj >= m))
                            ans += -1e9; // A very large negative value to represent an invalid move
                        else
                            ans += front[j1 + di][j2 + dj]; // Include the DP result from the next row

                        maxi = max(ans, maxi); // Update the maximum result
                    }
                }
                curr[j1][j2] = maxi; // Store the maximum result for this state in the DP array
            }
        }
        front = curr; // Move to the next row
    }

    // The maximum chocolates that can be collected is stored at the top-left corner of the DP array
    return front[0][m - 1];
}
int main()
{
    vector<vector<int>> grid =         
        {{2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5}};
    int n = grid.size();
    int m = grid[0].size();
    cout << maximumChocolates(n, m, grid) << endl;
    return 0;
}