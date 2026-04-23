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
void insertAtEnd(Node* &head, Node* &tail, int val){
    Node* new_node = new Node(val);
    if(tail == NULL){
        head = new_node;
        tail = new_node;
        return;
    }
    else{
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
}
void insertAtK(Node* &head, Node* &tail, int val, int k){
    Node* new_node = new Node(val);
    if(k == 0){
        insertAtStart(head, tail, val);
        return;
    }
    int count = 0;
    Node* temp = head;
    while (count < k - 1 ) {
        temp = temp->next;
        count++;
    }
    // Next pointers
    new_node->next = temp->next;
    temp->next = new_node;
    // Previous pointers
    new_node->prev = temp;
    new_node->next->prev = new_node;

return;
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
    insertAtEnd(head, tail, 60);
    insertAtEnd(head, tail, 70);
    display(head);
    insertAtK(head, tail, 25, 2);
    display(head);
    return 0;
}