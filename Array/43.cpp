#include<bits/stdc++.h>
using namespace std;
int cntAndMerge(vector<int>&arr, int l , int mid, int r){
    int n1 = mid - l + 1, n2 = r - mid;
    vector<int>left(n1);
    vector<int>right(n2);
    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[l+i];
    }
    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[mid+1+i];
    }
    int cnt = 0, i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if(left[i] <= right[j]) arr[k++] = left[i++];
        else
        {
            arr[k++] = right[j++];
            cnt += (n1 - i);
        }
        
    }
    while (i < n1)
    {
        arr[k++] = left[i++];
    }
    
    while (j < n2)
    {
        arr[k++] = right[j++];
    }
    
    return cnt;
}
int cntInversions(vector<int>&arr, int l , int r){
    int cnt = 0;
    if (l<r)
    {
        int mid = l+(r-l)/2;
        cnt+=cntInversions(arr,l,mid);
        cnt+=cntInversions(arr,mid+1, r);
        cnt+=cntAndMerge(arr,l,mid,r);
    }
    return cnt;
}
int main()
{
    vector<int>arr = {5,4,3,2,1};
    cout<<cntInversions(arr,0,4);
    return 0;
}