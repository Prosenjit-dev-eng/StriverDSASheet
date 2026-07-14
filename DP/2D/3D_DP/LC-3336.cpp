#include<bits/stdc++.h>
using namespace std;
    const int MOD = 1e9+7;
    // int t[201][201][201];
    /*int solve(vector<int>& nums, int i, int first, int second){
        int n = nums.size();
        if(i == n){
            if(first != 0 && second!=0 && first == second) return 1;
            else return 0;
        }
        if(t[i][first][second] != -1) return t[i][first][second]; 
        int skip = solve(nums,i+1,first,second);
        int take1 = solve(nums,i+1,__gcd(first,nums[i]),second);
        int take2 = solve(nums,i+1,first,__gcd(second,nums[i]));
        //(skip+take1+take2)=>This can be large, so convert into Long
        return t[i][first][second] = (0LL+skip+take1+take2)%MOD;

    }*/

    int subsequencePairCount(vector<int>& nums) {
        // return solve(nums,0,0,0);// nums,index,first seq's gcd, second seq'd gcd
        int n = nums.size();
        int maxEl = *max_element(nums.begin(),nums.end());

        int dp[n+1][maxEl+1][maxEl+1];// gcd can highest of a maxelement
        for (int first = 0; first <= maxEl; first++)
        {
            for(int second = 0; second <= maxEl; second++){
                dp[n][first][second] = (first!=0 && second != 0 && first == second) ? 1 : 0;
            }
        }
        // Als track from back due to i+1
        for (int i = n-1; i >= 0; i--)
        {
            for (int first = maxEl; first >= 0; first--) {
                for (int second = maxEl; second >= 0; second--) {

                    // Skip this index entirely
                    int skip  = dp[i + 1][first][second]; //solve(i+1, first, second);

                    // Include this index in seq1
                    int take1 = dp[i + 1][__gcd(first, nums[i])][second]; 

                    // Include this index in seq2
                    int take2 = dp[i + 1][first][__gcd(second, nums[i])];

                    dp[i][first][second] = (0LL + skip + take1 + take2) % MOD;
                }
            }
        }
        
        return dp[0][0][0];
    }
int main()
{
    vector<int>nums = {1,2,3,4};
    cout<<subsequencePairCount(nums)<<endl;
    return 0;
}