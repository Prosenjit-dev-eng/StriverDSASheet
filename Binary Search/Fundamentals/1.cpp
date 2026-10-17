#include<bits/stdc++.h>
using namespace std;
bool elementInSortedArray(int arr[], int n, int x){
    int low = 0, high = n-1;
    while(low<=high){
        int mid  = low + (high - low)/2;
        if(arr[mid] == x) return true;
        else if(x > arr[mid]) low = mid+1;
        else
        {
            high = mid - 1;
        }
        
    }
    return false;
}
// Recursively

int sameRecursively(int arr[], int n, int x, int low, int high){
    int mid  = low + (high - low)/2;
    
    // Basecase
    if(low>high) return -1;
    if(arr[mid] == x) return mid;
    else if (arr[mid]<x)
    {
        return (arr,n,x,mid+1,high);
    }
    else return(arr,n,x,low,mid-1);
    
}
// Time = o(logn)
/* n/2^k = 1
=> 2^k = n
=> k = logn */
int main()
{
    int arr[] = {1,2,3,4,5};
    int n = 5;
    int x = 5;
    cout<<elementInSortedArray(arr,n,x)<<endl;
    cout<<sameRecursively(arr,n,x,0,n-1)<<endl;
    return 0;
}