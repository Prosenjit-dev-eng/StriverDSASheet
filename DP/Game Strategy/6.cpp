#include<bits/stdc++.h>
using namespace std;
int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
    int n = aliceValues.size();
    int scoreA = 0, scoreB = 0;
    vector<pair<int,int>>p;// sum and index
    for (int i = 0; i < n; i++)
    {
        p.push_back({aliceValues[i]+bobValues[i],i});
    }
    sort(p.rbegin(),p.rend());
    for (int i = 0; i < n; i++)
    {
        int idx = p[i].second;

        if(i%2 == 0){
            scoreA += aliceValues[i];
        }
        else scoreB += bobValues[i];
    }
    if(scoreA > scoreB) return 1;
    else if (scoreA < scoreB ) return -1;
    else return 0;   
}
int main()
{
    vector<int>a = {2,4,3};
    vector<int>b = {1,6,7};
    cout<<stoneGameVI(a,b)<<endl;
    return 0;
}