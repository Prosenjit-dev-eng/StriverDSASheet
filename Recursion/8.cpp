#include<bits/stdc++.h>
using namespace std;
// This structure should be remembered
// Print all subsets of an array
void printF(int idx, vector<int>&ds,int arr[], int n){
    if (idx == n)
    {
        for (int i = 0; i < ds.size(); i++)
        {
            cout<<ds[i]<<" ";
        }
        cout<<endl;
        return;
    }
    // Pick
        ds.push_back(arr[idx]);
        printF(idx+1,ds,arr,n);
    // Not pick
        ds.pop_back();
        printF(idx+1,ds,arr,n);
    
    
}
int main()
{
    int arr[] = {3,1,2};
    int n = 3;
    vector<int>ans;
    printF(0,ans,arr,n);
    return 0;
}