#include<bits/stdc++.h>
using namespace std;
// Max Heap & Min Heap
class Heap{
    public:
    int arr[100];
    int size;
    Heap(){
        arr[0]=0;
        size=0;
    }
 //Time Complexity: O(log n)
    void insertatMaxHeap(int val){
        size++;
        int idx=size;
        arr[idx]=val;
        while (idx > 1)
        {
            int parent=idx/2;
            if(arr[parent]<arr[idx]){
                swap(arr[parent],arr[idx]);
                idx=parent;
            }
            else{
                return;
            }
        }
        
    }
    void insertatMinHeap(int val){
        size++;
        int idx=size;
        arr[idx]=val;
        while (idx > 1)
        {
            int parent=idx/2;
            if(arr[parent]>arr[idx]){
                swap(arr[parent],arr[idx]);
                idx=parent;
            }
            else{
                return;
            }
        }
        
    }
    void deletefromHeap(){
        if(size==0){
            cout<<"Nothing to delete"<<endl;
            return;
        }
        arr[1]=arr[size];
        size--;
        // take root to its correct position
        int i=1;
        while (i<size)
        {
            int leftIndex=2*i;// left child index
            int rightIndex=2*i+1;// right child index
            if(leftIndex<size && arr[i]<arr[leftIndex]){
                swap(arr[i],arr[leftIndex]);
                i=leftIndex;
            }
            else if(rightIndex<size && arr[i]<arr[rightIndex]){
                swap(arr[i],arr[rightIndex]);
                i=rightIndex;
            }
            else{
                return;
            }
        }
        
    }
    void heapify(int arr[],int n,int i){
        int largest=i;
        int left=2*i;
        int right=2*i+1;
        if(left<=n && arr[largest]<arr[left]){
            largest=left;
        }
        if(right<=n && arr[largest]<arr[right]){
            largest=right;
        }
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
    }
    
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    Heap h1,h2;
    h1.insertatMaxHeap(50);
    h1.insertatMaxHeap(55);
    h1.insertatMaxHeap(53);
    h1.insertatMaxHeap(52);
    h1.insertatMaxHeap(54);
    h1.print();
    // h1.deletefromHeap();
    // h1.print();
    h2.insertatMinHeap(50);
    h2.insertatMinHeap(55);
    h2.insertatMinHeap(53);
    h2.insertatMinHeap(52);
    h2.insertatMinHeap(54);
    h2.print();

    return 0;
}