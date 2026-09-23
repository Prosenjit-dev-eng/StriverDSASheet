#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {
    int p = 0;
    int mi = prices[0];
    for(int i = 1; i < prices.size(); i++){
        int cp = prices[i] - mi;
        p = max(p,cp);
        mi = min(mi,prices[i]);
    }
    return p;
}

int main()
{
    vector<int>prices = {7,1,2,5,6};
    cout<<maxProfit(prices)<<endl;
    return 0;
}