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
int sum(vector<int>& v, int n){
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += v[i];
    }
    return ans;
}
int noOfDays(vector<int>& v, int n, int cap){
    int load = 0,days = 1;
    for (int i = 0; i < n; i++)
    {
       if( load  + v[i]> cap){
        days++;
        load =  v[i];
       }
       else{
        load += v[i];
       } 
    }
    return days;
}
int leastWeights(vector<int>& v, int n, int d){
    int low = maximum(v,n), high = sum(v,n);
    while (low<=high)
    {
        int mid = low + (high - low)/2;
        if((noOfDays(v,n,mid))<=d){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
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
    int d;
    cin>>d;
    cout<<leastWeights(v,n,d)<<endl;
    return 0;
}