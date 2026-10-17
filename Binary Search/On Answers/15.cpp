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
int divisorSum(vector<int>& v, int n, int x){
    int totalDivisors = 0;
    for (int i = 0; i < n; i++)
    {
        totalDivisors += ceil((double)v[i]/(double)x);// hourly = how much it will eat
    }
    return totalDivisors;
}// O(n)
int smallestDivisors(vector<int>& v, int n,int limit){
    int low = 1, high = maximum(v,n);
    while (low<=high)
    {
        int mid = low + (high - low)/2;
        int total = divisorSum(v,n,mid);
        if(total<=limit){// check the case
            high = mid - 1;
        }
        else{
            low = mid+1;
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
    int limit;
    cin>>limit;
    cout<<smallestDivisors(v,n,limit)<<endl;
    return 0;
}