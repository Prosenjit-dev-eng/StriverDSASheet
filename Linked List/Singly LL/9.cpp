#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
// Mthod 1, T.C. = o(k^2 * n), S.C. = o(1)
Node* merge(Node*h1, Node*h2){
    // Dummy node with zero
    Node* head = new Node(0);
    Node* tail = head;
    while (h1 && h2)
    {
        if(h1->data<=h2->data){
            tail->next = h1;
            h1 = h1->next;
            tail = tail->next;
            tail->next = NULL;
        }
        else{
            tail->next = h2;
            h2 = h2->next;
            tail = tail->next;
            tail->next = NULL;
        }
    }
    if(h1)
    {
        tail->next = h1;
    }
    if(h2)
    {
        tail->next = h2;
    }
    return head->next;// Bcz 1st Node is dummy node
       
}
Node* mergeK(Node *arr[], int k){
    Node* head = arr[0];
    for (int i = 1; i < k; i++)
    {
        head = merge(head, arr[i]);
    }
    return head;
}
void display(Node* head){
    Node* temp = head;
    while (temp)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
}
int main()
{
    Node* arr[8];
    arr[0] = new Node(1);
    arr[0]->next = new Node(2);
    arr[0]->next->next = new Node(4);

    arr[1] = new Node(3);
    arr[1]->next = new Node(6);

    arr[2] = new Node(4);
    arr[2]->next = new Node(5);
    arr[2]->next->next = new Node(9);
    arr[2]->next->next->next = new Node(10);

    arr[3] = new Node(7);

    arr[4] = new Node(6);
    arr[4]->next = new Node(8);

    arr[5] = new Node(2);
    arr[5]->next = new Node(7);
    arr[5]->next->next = new Node(8);
    arr[5]->next->next->next = new Node(10);

    arr[6] = new Node(17);
    arr[6]->next = new Node(19);
    arr[6]->next->next = new Node(22);

    arr[7] = new Node(4);
    arr[7]->next = new Node(18);
    Node* mergedHead = mergeK(arr, 8);
    display(mergedHead);
    return 0;
}