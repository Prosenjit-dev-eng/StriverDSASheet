#include<bits/stdc++.h>
using namespace std;
int maximum(vector<int>& v, int n){
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi,v[i]);
    }
    return maxi;
}
int minimum(vector<int>& v, int n){
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini,v[i]);
    }
    return mini;
}
bool possible(vector<int>&v, int n,int day,int m, int k){
    int count = 0, noOfBouquets = 0;
    for (int i = 0; i < n; i++)
    {
        if(v[i]<=day) count++;
        else{
            noOfBouquets += (count/k);// 3 = 1
            count = 0;// restart count at zero
        } 
    }
    noOfBouquets += count/k;// 2
    if(noOfBouquets >= m) return true;
    return false;
}
int minBouquets(vector<int>&v, int n, int m, int k){
    int low = minimum(v,n), high = maximum(v,n);
    if(m*k>n) return -1;
    int ans = 0;
    while (low<=high)
    {
        int mid = low + (high - low)/2;
        if(possible(v,n,mid,m,k)){
            ans = mid;
            high = mid - 1;// we need minimum
        }
        else low = mid + 1;
    }
    return low;
}
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    int m,k;
    cin>>m>>k;

    cout<<minBouquets(v,n,m,k)<<endl;
    return 0;
}