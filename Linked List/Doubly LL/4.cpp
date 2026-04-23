#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node*prev;
    Node*next;
    Node(int data){
        val = data;
        prev = NULL;
        next = NULL;
    }

};
void deleteAtHead(Node* &head, Node* &tail){
    if(head == NULL) return; // List is empty
    Node* temp = head;
    head = head->next;
    if(head != NULL) {
        head->prev = NULL;
    } else {
        tail = NULL; // If the list becomes empty
    }
    free(temp);
}
void deleteAtTail(Node* &head, Node* &tail){
    if(tail == NULL) return; // List is empty
    Node* temp = tail;
    tail = tail->prev;
    if(tail != NULL) {
        tail->next = NULL;
    } else {
        head = NULL; // If the list becomes empty
    }
    free(temp);
}
Node* deleteOccurences(Node* &head, int target){
    if(head == NULL){
        return head;
    }
    Node* temp = head;
    while (temp!=NULL)
    {
        if(temp->val == target){
            if(temp == head){
                head = head->next;
            }
            Node*last = temp->prev;
            Node* front = temp->next;
            if(last!=NULL) last->next = front;
            if(front!=NULL) front->prev = last;
            free(temp);
            temp = temp->next;
        }
        else
        {
            temp = temp -> next;
        }
        
    }
    return head;
}

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
    insertAtStart(head, tail, 10);
    insertAtStart(head, tail, 20);
    insertAtStart(head, tail, 10);
    cout << "Original List: "; 
    display(head);
    int target = 10;
    head = deleteOccurences(head, target);
    cout << "List after deleting occurrences of " << target << ": "; 
    display(head);
    return 0;
}