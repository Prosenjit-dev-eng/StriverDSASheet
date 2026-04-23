#include<bits/stdc++.h>
using namespace std;
// This structure should be remembered
// Print all subsets of an array

bool printOne(int idx, vector<int>&ds,int arr[], int n, int s, int sum){
    if (idx == n)
    {
        if(s == sum){
        for (int i = 0; i < ds.size(); i++)
        {
            cout<<ds[i]<<" ";
        }
        cout<<endl;

        return true;
        }
        return false;
    }
    // Pick
        ds.push_back(arr[idx]);
        s+=arr[idx];
        if((printOne(idx+1,ds,arr,n,s,sum)) == true) return true;
    // Not pick
        ds.pop_back();
        s-=arr[idx];
        if((printOne(idx+1,ds,arr,n,s,sum)==true)) return true;
}
int main()
{
    int arr[] = {3,1,2};
    int n = 3;
    vector<int>ans;
    int s = 0, sum = 2;
    printOne(0,ans,arr,n,s,sum);
    return 0;
}