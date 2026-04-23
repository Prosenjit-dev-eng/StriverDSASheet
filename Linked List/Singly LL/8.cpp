#include<bits/stdc++.h>
using namespace std;
// Flattening a LL
class Node{
    public:
    int data;
    Node*next;
    Node* bottom;
    Node(int val){
        data = val;
        next = NULL;
        bottom = NULL;
    }
};
Node* merge(Node*h1, Node*h2){
    // Dummy node with zero
    Node* head = new Node(0);
    Node* tail = head;
    while (h1 && h2)
    {
        if(h1->data<=h2->data){
            tail->bottom = h1;
            h1 = h1->bottom;
            tail = tail->bottom;
            tail->bottom = NULL;
        }
        else{
            tail->bottom = h2;
            h2 = h2->bottom;
            tail = tail->bottom;
            tail->bottom = NULL;
        }
    }
    if(h1)
    {
        tail->bottom = h1;
    }
    if(h2)
    {
        tail->bottom = h2;
    }
    return head->bottom;// Bcz 1st Node is dummy node
       
}
Node* flattenList(Node* root){
        Node* h1,*h2,*h3;
    while (root->next)
    {
        h1 = root;
        h2 = root->next;
        h3 = root->next->next;

        h1->next = NULL;
        h2->next = NULL;
        root = merge(h1,h2);
        root->next = h3;
    }
    return root;

}
void display(Node* head){
    Node* temp = head;
    while (temp)
    {
        cout<<temp->data<<"->";
        temp = temp->bottom;
    }
    cout<<"NULL";
}
int main()
{
    Node* root = new Node(5);
    root->bottom = new Node(7);
    root->bottom->bottom = new Node(8);
    root->bottom->bottom = new Node(30);

    root->next = new Node(10);
    root->next->bottom = new Node(20);
    root->next->bottom->bottom = new Node(40);

    root->next->next = new Node(19);
    root->next->next->bottom = new Node(22);
    root->next->next->bottom->bottom = new Node(50);

    root->next->next->next = new Node(28);
    root->next->next->next->bottom = new Node(35);
    root->next->next->next->bottom->bottom = new Node(40);
    root->next->next->next->bottom->bottom->bottom = new Node(45);

    root->next->next->next->next = new Node(30);
    root->next->next->next->next->bottom = new Node(34);
    root->next->next->next->next->bottom->bottom = new Node(40);

    Node*f = flattenList(root);
    display(f);
    return 0;
}