#include<bits/stdc++.h>
using namespace std;
class MaxHeap{
    private:
    vector<int>heap;
    // For insertion
    void heapifyUp(int idx){
        while (idx > 0)
        {
            int parent = (idx-1)/2;// parent
            if (heap[parent] < heap[idx])
            {
                swap(heap[parent],heap[idx]);
                idx = parent;
            }
            else
            {
                return;
            }
            
        }
        
    }
    void heapifyDown(int idx){
        int n = heap.size();
        while (true)
        {
            int largest = idx;
            int left = 2*idx + 1;
            int right = 2*idx + 2;
            if (left < n && heap[left] > heap[largest])
            {
                largest = left;
            }
            if (right < n && heap[right] > heap[largest])
            {
                largest = right;
            }
            if (largest == idx)
            {
                break;
            }
            swap(heap[idx],heap[largest]);
            idx = largest;
            
        }
        
    }
    public:
    // Initialization
    MaxHeap(){
        heap.clear();
    }
    void insert(int x){
        heap.push_back(x);
        heapifyUp(heap.size() - 1);//The new element is always added at the end of the vector.
        // So we start from last index
    }
    int getMax(){
        if (heap.empty())
        {
            throw runtime_error("Heap is empty");
        }
        return heap[0];
        
    }
    void extractMax(){
        if(heap.empty()) return;

        swap(heap[0],heap.back());// Swap the last element with the last
        heap.pop_back();
        if (!heap.empty())
        {
            heapifyDown(0);
        }
        
    }
    int heapSize(){
        return heap.size();
    }
    bool isEmpty(){
        return heap.empty();
    }
    void changeKey(int index, int new_val){
        if(index < 0 || index >= heap.size()) return;
        int oldval = heap[index];
        heap[index] = new_val;
        if(new_val > oldval) heapifyUp(index);
        else heapifyDown(index);
    }
    void printHeap(){
        for(int x : heap) cout<<x<<" ";
        cout<<'\n';
    }
};
int main()
{
    MaxHeap h;

    h.insert(10);
    h.insert(40);
    h.insert(50);
    h.insert(100);
    h.insert(20);
    h.insert(90);
    
    cout<<"Max: "<<h.getMax()<<endl;
    cout<<"Size: "<<h.heapSize()<<endl;

    h.changeKey(2,110);
    cout<<"Max: "<<h.getMax()<<endl;
    h.extractMax();
    cout<<"Max: "<<h.getMax()<<endl;
    h.printHeap();
    return 0;
}