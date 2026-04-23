#include<bits/stdc++.h>
using namespace std;
int minCoins(vector<int>v, int k){
    sort(v.begin(),v.end(),greater<int>());
    int cnt = 0;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        if(v[i]<=k){
            cnt++;
            k = k - v[i];
        }
    }
    return cnt;
}
int main()
{
    vector<int>V = {1,2,5,10,20,50,100,200,500,1000};
    int k = 121;
    cout<<minCoins(V,k)<<endl;

    return 0;
}