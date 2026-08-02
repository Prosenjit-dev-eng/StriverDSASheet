#include<bits/stdc++.h>
using namespace std;
// Lc-948,881 etc.
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(),tokens.end());
        int i = 0, j = n - 1;
        int maxScore = 0;
        int score = 0;
        while(i <= j){
            if(power >= tokens[i]){
                power -= tokens[i];
                i++;
                score += 1;
                maxScore = max(maxScore,score);
            }
            else if(score >= 1){
                power += tokens[j];
                j--;
                score -= 1;
            }
            else return maxScore;
        }
        return maxScore;
    }
int main()
{
    vector<int> tokens = {100,200,300,400};
    cout<<bagOfTokensScore(tokens,200)<<endl;
    return 0;
}