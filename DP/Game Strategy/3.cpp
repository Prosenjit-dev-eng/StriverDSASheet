#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    int t[101][101][2];
    int solve(int i, int M, int person,vector<int>& piles){
        if(i >= n) return 0;
        int score = 0;
        int res = (person == 1) ? -1 : INT_MAX;
        if(t[i][M][person] != -1) return t[i][M][person];
        for(int x = 1; x <= 2*M; x++){
            if(i+x <= n) score += piles[i+x-1];
            if(person == 1){//Alice
                res = max(res,score+solve(i+x,max(M,x),0,piles));
            }
            else res = min(res,solve(i+x,max(M,x),1,piles));//Bob, no stone, that is taken by bob
        }
        return t[i][M][person] = res;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(t,-1,sizeof(t));
        return solve(0,1,1,piles);// index,M, person, piles
    }
};
int main()
{
    Solution sol;
    vector<int>piles = {2,7,9,4,4};
    cout<<sol.stoneGameII(piles)<<endl;
    return 0;
}