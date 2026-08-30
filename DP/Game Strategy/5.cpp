#include<bits/stdc++.h>
using namespace std;
// int solve(vector<int>& prefSum, int l, int r) {
//     if (l >= r) return 0;
//     int score = 0;

//     for (int i = l; i <= r; i++) {
//         int leftSum = prefSum[i] - (l > 0 ? prefSum[l - 1] : 0);
//         int rightSum = prefSum[r] - prefSum[i];
//         if (leftSum < rightSum) {
//             score = max(score, leftSum + solve(prefSum, l, i));
//         } else if (leftSum > rightSum) {
//             score = max(score, rightSum + solve(prefSum, i + 1, r));
//         } else {
//             score = max({score, leftSum + solve(prefSum, l, i), rightSum + solve(prefSum, i + 1, r)});
//         }
//     }
//     return score;
// }
int stoneGameV(vector<int>& stoneValue) {
    /*vector<int> prefSum(stoneValue.size());
    for(int i = 0; i < stoneValue.size(); i++) {
        if(i == 0) prefSum[i] = stoneValue[i];
        else prefSum[i] = prefSum[i - 1] + stoneValue[i];
    }
    return solve(prefSum, 0, stoneValue.size() - 1);*/
    int n = stoneValue.size();
    vector<int> prefSum(n);
    for(int i = 0; i < n; i++) {
        if(i == 0) prefSum[i] = stoneValue[i];
        else prefSum[i] = prefSum[i - 1] + stoneValue[i];
    }
    vector<vector<int>>t(n,vector<int>(n,0));
    for (int l = n-1; l >= 0; l--)
    {
        for (int r = l+1; r < n; r++)
        {
           int score = 0;
        for (int mid = l; mid < r; mid++)
        {
            int leftSum = prefSum[mid] - (l > 0 ? prefSum[l - 1] : 0);
            int rightSum = prefSum[r] - prefSum[mid];
            if (leftSum < rightSum) {
                score = max(score, leftSum + t[l][mid]);
            } else if (leftSum > rightSum) {
                score = max(score, rightSum + t[mid+1][r]);
            } else {
                score = max({score, leftSum + t[l][mid], rightSum + t[mid+1][r]});
            }
        }
        t[l][r] = score;
        
       }
       
    }
    return t[0][n-1];
    
}
int main()
{
    vector<int> stoneValue = {6,2,3,4,5,5};
    cout<<stoneGameV(stoneValue)<<endl;
    return 0;
}