#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int val;
    node* next;
    node(int data){
        val = data;
        next = NULL;
    }
};

void deleteAtHead(node*&head){
    node*temp = head;
    head = temp->next;
    free(temp);
}
void deleteAtTail(node*&head){
    node*temp = head;
    while (temp->next->next!=NULL)
    {
        temp = temp->next;
    }
    // temp is now at the second last node
    // we need to delete the last node
    node*last_node = temp->next;
    temp->next = NULL;
    free(last_node);
    
}

void deleteAtK(node* &head, int k){
    if(k==1){ 
        deleteAtHead(head);
        return;
    }

    node*temp = head;
    int pos = 0;
    while (pos != k - 1)
    {
        temp = temp->next;
        pos++;
    }
    node*deleted = temp->next;
    if(temp->next->next == NULL){
        deleteAtTail(head);
    }
    else temp->next = temp->next->next;
    free(deleted);
}

void display(node*head){
    node*temp = head;
    while (temp!=NULL)
    {
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}


int main()
{
    vector<int>v = {1,2,3,4,5};
    node*head = new node(v[0]);
    head->next = new node(v[1]);
    head->next->next = new node(v[2]);
    head->next->next->next = new node(v[3]);
    head->next->next->next->next = new node(v[4]);

    deleteAtHead(head);
    deleteAtTail(head);
    deleteAtK(head,2);
    display(head);


    return 0;
}