#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maximum(vector<int> &arr, int n){
    int maxi = arr[0];
    for (int i = 1; i < n; i++)
    {
        if(arr[i]>maxi){
            maxi = arr[i];
        }
    }// Time = o(n)
    
    return maxi;
}
int minimum(vector<int> &arr, int n){
    int mini = arr[0];
    for (int i = 1; i < n; i++)
    {
        if(arr[i]<mini){
            mini = arr[i];
        }
    }
    
    return mini;
}// Time = o(n)
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    cout<<maximum(arr, n)<<endl;
    cout<<minimum(arr, n)<<endl;

    return 0;
}