#include<bits/stdc++.h>
using namespace std;
// Ninja Training
// Recursively
// Last is used what i did in previous index
/*int f(int day, int last, vector<vector<int>> &points){->f(n-1,3)
    // Base case
    if(day == 0){
        int maxAct = 0;
        for(int task = 0; task < 3; task++){
            if(task != last) maxAct = max(maxAct, points[0][task]);// 0th day's task
        }
        return maxAct;
    }
    int maxAct = 0;
    for(int task = 0; task < 3; task++){
        if(task != last) {
            maxAct = points[day][task] + f(day - 1, task, points);
        }
    }
    return maxAct;
}*/
// Memoization
/*int f(int day, int last, vector<vector<int>> &points){
    vector<vector<int>> dp(n, vector<int>(4, -1));
    if(day == 0){
        int maxAct = 0;
        for(int task = 0; task < 3; task++){
            if(task != last) maxAct = max(maxAct, points[0][task]);
        }
        return maxAct;
    }
    if(dp[day][last] != -1) return dp[day][last];
    int maxAct = 0;
    for(int task = 0; task < 3; task++){
        if(task != last) {
        maxAct = points[day][task] + f(day - 1, task, points);
        }
    }
    return dp[day][last] = maxAct;
}*/
// tabulation
/*int ninjaTraining(int n, vector<vector<int>> &points) {
    // return f(n - 1, 3, points);// cols = 3, last = 3 means no task was done on previous day
    // Tabulation
    // we can make this function for it
    vector<vector<int>> dp(n, vector<int>(4, 0)); 
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max({points[0][0], points[0][1], points[0][2]}); 
    for(int day = 1; day < n; day++){
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if(task != last) {
                    int point = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last],point);
                }
            }
        
        }
    }
    return dp[n-1][3];
    
}*/
// Space optimisation
int ninjaTraining(int n, vector<vector<int>> &points) {
    vector<int>prev(4,0);

    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max({points[0][0], points[0][1], points[0][2]}); 
    for(int day = 1; day < n; day++){
        vector<int>temp(4,0);
        for (int last = 0; last < 4; last++)
        {
            temp[last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if(task != last) {
                    int point = points[day][task] + prev[task];
                    temp[last] = max(temp[last],point);
                }
            }
        
        }
        prev = temp;
    }
    return prev[3];
    
}
int main()
{
    vector<vector<int>> points = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};
    int n = points.size();
    cout<<ninjaTraining(n, points);
    return 0;
}