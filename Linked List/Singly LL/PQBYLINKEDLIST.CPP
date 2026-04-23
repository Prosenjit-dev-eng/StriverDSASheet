#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};

void pq(Node *& head,int val){
    Node* newNode = new Node(val);
    if(head == NULL || head->data>val) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next!=NULL && temp->next->data<val)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;    
 
    
}
void display(Node *head){
    Node* temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
    
}
int main()
{
    Node* head = NULL;
    pq(head,20);
    pq(head,2);
    pq(head,7);
    pq(head,7);
    pq(head,13);
    pq(head,9);
    pq(head,14);
    display(head);


    return 0;
}