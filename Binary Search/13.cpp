#include<bits/stdc++.h>
using namespace std;
// It is for range
int maximum(vector<int>& v, int n){
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi,v[i]);
    }
    return maxi;
}

int totalTime(vector<int>& v, int n, int hourly){
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += ceil((double)v[i]/(double)hourly);// hourly = how much it will eat
    }
    return total;
}// O(n)

int minimumK(vector<int>& v, int n, int h){
    int low = 1, high = maximum(v,n);
    while (low<=high)
    {
        int mid = low + (high - low)/2;
        int total = totalTime(v,n,mid);
        if(total<=h){// check the case
            high = mid - 1;
        }
        else{
            low = mid+1;
        }
    }
    return low;// We can find it left side
}// O(logn)
// Overall = o(n*logn)
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    int h;
    cin>>h;

    cout<<minimumK(v,n,h)<<endl;
    return 0;
}