#include<bits/stdc++.h>
using namespace std;
// This structure should be remembered
// Print all subsets of an array

void printCombinationSum(int idx, vector<int>&ds,int arr[], int n, int s, int sum){
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
    // Pick: stay at the same index
    if(s+arr[idx]<=sum){
        ds.push_back(arr[idx]);
        printCombinationSum(idx,ds,arr,n,s+arr[idx],sum);
        ds.pop_back();
    }
    // Not pick
    printCombinationSum(idx+1,ds,arr,n,s,sum);

}
int main()
{
    int arr[] = {2,3,6,7};
    int n = 4;
    vector<int>ans;
    int s = 0, target = 7;
    printCombinationSum(0,ans,arr,n,s,target);
    return 0;
}