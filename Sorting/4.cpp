#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>&v, int l, int mid, int r){
    int an = mid - l+1;
    int bn = r - mid;
    vector<int>a(an);
    vector<int>b(bn);
    for (int i = 0; i < an; i++)
    {
        a[i] = v[l+i];
    }
    for (int j = 0; j < bn; j++)
    {
        b[j] = v[(mid+1)+j];
    }
    
    int i = 0, j = 0, k = l;
    while (i < an && j < bn)
    {
        if (a[i] < b[j])
        {
            v[k++] = a[i++];

        }
        else v[k++] = b[j++];
        
    }
    while (i < an)
    {
        v[k++] = a[i++];
    }
    while (j < bn)
    {
        v[k++] = b[j++];
    }
    
}
void mergeSort(vector<int>&v, int l, int r){
    if (l>=r)
    {
        return;
    }
    int mid = (l+r)/2;
    mergeSort(v,l,mid);
    mergeSort(v,mid+1,r);
    merge(v,l,mid,r);
    
}
int main()
{
    vector<int> arr = {1,5,4,9,3,8,6,7};
    mergeSort(arr, 0, 7);
    for (int i = 0; i < 8; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}