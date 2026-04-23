#include<bits/stdc++.h>
using namespace std;
/*void buildMaxHeap(int arr[],int i, int n){
    while (i>0)
    {
        int parentidx = (i-1)/2;
        if(arr[parentidx]<arr[i]){
            swap(arr[i],arr[parentidx]);
            i = parentidx;
        }
        else
        {
            break;
        }
        
    }
    
}//T.c. => o(nlogn)*/
void heapify(int arr[],int n,int i){
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left<n && arr[largest]<arr[left]){
            largest=left;
        }
        if(right<n && arr[largest]<arr[right]){
            largest=right;
        }
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
}
void buildMaxHeap(int arr[],int n){
    for (int i = n/2-1; i >= 0 ; i--)
    {
        heapify(arr,n,i);
    }
}
int main()
{
    int arr[] = {14,15,12,22,17,20,18,24,23,30,19};
    int n = sizeof(arr)/sizeof(arr[0]);
    buildMaxHeap(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
    return 0;
}