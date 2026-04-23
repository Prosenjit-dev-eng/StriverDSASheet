#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node* prev;
    Node* next;
    Node(int data){
        val = data;
        prev = NULL;
        next = NULL;
    }
};

void insertAtStart(Node* &head, Node* &tail,int val){
    Node* new_node = new Node(val);
    if(head == NULL){
        head = new_node;
        tail = new_node;
        return;
    }
    else{
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }

}
Node* reverseDLL(Node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* curr = head;
    Node* last = NULL;
    while (curr!=NULL)
    {
        // Swapping the linkages
        last = curr->prev;
        curr->prev = curr->next;
        curr->next = last;
        // Increment
        curr = curr->prev;// bcz it has swapped
    }
    head = last->prev; // new head
    return head;
}
void display(Node* head){
        Node* temp = head;
        while (temp!=NULL)
        {
            cout<<temp->val<<"<->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;

}
int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertAtStart(head, tail, 10);
    insertAtStart(head, tail, 20);      
    insertAtStart(head, tail, 30);
    insertAtStart(head, tail, 40);
    insertAtStart(head, tail, 50);
    display(head);
    reverseDLL(head);
    cout<<"After reverse: "<<endl;
    display(head);
    return 0;
}