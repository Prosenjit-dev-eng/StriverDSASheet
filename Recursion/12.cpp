#include<bits/stdc++.h>
using namespace std;
// This structure should be remembered
// Print all subsets of an array

int countS(int idx,int arr[], int n, int s, int sum){
    if (idx == n)
    {
        // Condition satisfied
        if(s == sum) return 1;
        // Condition unsatisfied

        else return 0;

    }

    // Pick
        s += arr[idx];
        int l = countS(idx+1,arr,n,s,sum);
    // Not pick
        s-=arr[idx];
        int r = countS(idx+1,arr,n,s,sum);
        return l+r;

}
bool isExist(int idx, int arr[], int n, int s,int sum ){
    if (countS(idx,arr,n,s,sum) >= 1)
    {
        return true;
    }
    return false;
}
int main()
{
    int arr[] = {1,2,1};
    int n = 3;
    vector<int>ans;
    int s = 0, sum = 2;
    cout<<isExist(0,arr,n,s,sum)<<endl;
    return 0;
}