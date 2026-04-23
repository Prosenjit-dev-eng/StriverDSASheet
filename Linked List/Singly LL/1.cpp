#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};
void insertAtHead(node* &head, int val) {
    node* new_node = new node(val);
    new_node->next = head;
    head = new_node;

}
void insertAtTail(node* &head, int val){
    node*new_node = new node(val);
    if(head == NULL){
        head = new_node;
        return;
    }
    node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;

}// time = o(n)

void insertAtK(node* &head, int val, int k){
    node* new_node = new node(val);
    if(k == 0){
        insertAtHead(head,val);
    }
    node*temp = head;
    int cur_pos = 0;
    while (cur_pos!=k-1 && temp!=NULL)// here we can't use temp->next != k-1, bcz temp->next is a pointer
    {
        temp = temp -> next;
        cur_pos++;
    }
    // This steps are crucial
    new_node ->next = temp->next;
    temp ->next = new_node;

}

void updateAtK(node* &head, int val, int k){
    node* temp = head;
    int cur_pos = 0;
    while (cur_pos!=k && temp!=NULL)
    {
        temp = temp -> next;
        cur_pos++;
    }
    if(temp != NULL){
        temp->data = val;
    }
    else{
        cout<<"Position out of bounds"<<endl;
    }
}
void display(node* head){
    node* temp = head;
    // traversing
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    node* a = new node(12);
    cout<<a->data<<endl;

    vector<int>v = {1, 2, 3, 4, 5};
    node*head = new node(v[0]);
    head->next = new node(v[1]);
    head->next->next = new node(v[2]);
    head->next->next->next = new node(v[3]);
    head->next->next->next->next = new node(v[4]);
    insertAtHead(head, 10);

    insertAtTail(head,300);

    insertAtK(head,4,1);
    display(head);
    updateAtK(head, 100, 2);
    display(head);
    return 0;
}