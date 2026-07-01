#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    int row, col;
    Node(int val, int i, int j){
        data = val;
        row = i;
        col = j;
    }
};
class Compare{
    public:
    bool operator()(Node*a, Node*b){
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>& arr, int k) {
    priority_queue<Node*,vector<Node*>,Compare>pq;
    // Insert the first element of each array
    for (int i = 0; i < k; i++)
    {
        Node* temp = new Node(arr[i][0], i, 0);
        pq.push(temp);
    }
    vector<int>ans;
    while (!pq.empty())
    {
        Node* temp = pq.top();
        ans.push_back(temp->data);
        pq.pop();
        int i = temp->row;
        int j = temp->col;
        if (j+1 < arr[i].size())
        {
            Node* next = new Node(arr[i][j+1], i, j+1);
            pq.push(next);
        }
        
    }
    return ans;
    
}
int main()
{
    vector<vector<int>> arr =  {{1,2,3},{4,5,6},{7,8,9}};
    int k = 3;
    vector<int>res = mergeKSortedArrays(arr,k);
    for(int i : res) cout<<i<<" ";
    return 0;
}