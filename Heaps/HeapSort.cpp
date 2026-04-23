#include<bits/stdc++.h>
using namespace std;
// (i) Array -> maxheap
void heapify(int arr[],int i,int n){
    int largest = i;
    int lc = 2*i+1;
    int rc = 2*i+2;
    if (lc<n && arr[largest]<arr[lc])
    {
        largest = lc;
    }
    if (rc<n && arr[largest]<arr[rc])
    {
        largest = rc;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,largest,n);
    }
}
void buildMaxHeap(int arr[], int n){
    for (int i = n/2 - 1; i>=0; i--)
    {
        heapify(arr,i,n);
    }
    
}
//Delete
void deleteAtMaxHeap(int arr[], int n){
    // We should do the deletion repeatedly
    buildMaxHeap(arr,n);
    for (int i = n-1; i >0; i--)
    {
        swap(arr[i],arr[0]);
        // size becomes i , bcz it points at n-1;
        heapify(arr,0,i);
    }
    
    
}
void heapSort(int arr[], int n){
    //(i)Array to maxheap
    buildMaxHeap(arr,n);
    //(ii) Delete & heapify
    deleteAtMaxHeap(arr,n);
}
int main()
{
    int arr[6] = {3, 2, 1, 5, 6, 4};
    heapSort(arr,6);
    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}