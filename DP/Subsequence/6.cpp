#include<bits/stdc++.h>
using namespace std;
int solve(int i, int target, vector<int>& price){
    if(target == 0) return 0;
    if( i < 0) return 0;
    int pick = 0;
    int curlength = i + 1;

    if(target >= curlength) pick = price[i]+ solve(i,target - curlength,price);
    int notpick = solve(i-1,target,price);
    return max(pick,notpick);

}
int cutRod(vector<int>& price) {
    int n = price.size();
    return solve(n - 1, n, price);
}
int main()
{
    vector<int>price = {2, 5, 7, 8};
    cout<<cutRod(price)<<endl;
    return 0;
}