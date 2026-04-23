#include<bits/stdc++.h>
using namespace std;
// This structure should be remembered
// Print all subsets of an array

void printS(int idx, vector<int>&ds,int arr[], int n, int s, int sum){
    if (idx == n)
    {
        if(s == sum){
        for (int i = 0; i < ds.size(); i++)
        {
            cout<<ds[i]<<" ";
        }
        cout<<endl;
    }
    return;
    }
    // Pick
        ds.push_back(arr[idx]);
        s+=arr[idx];
        printS(idx+1,ds,arr,n,s,sum);
    // Not pick
        ds.pop_back();
        s-=arr[idx];
        printS(idx+1,ds,arr,n,s,sum);

}
int main()
{
    int arr[] = {1,2,1};
    int n = 3;
    vector<int>ans;
    int s = 0, sum = 2;
    printS(0,ans,arr,n,s,sum);
    return 0;
}