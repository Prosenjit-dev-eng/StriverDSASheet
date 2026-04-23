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
void deleteAtK(Node* &head, Node* &tail, int k){

    Node* temp = head;
    int count = 1;
    while(temp != NULL && count < k) {
        temp = temp->next;
        count++;
    }
    if(temp == NULL) return; // k is out of bounds
    Node*prev_node = temp->prev;
    Node*front = temp->next;
    if(prev_node == NULL && front == NULL){
        free(temp);
        return; // Only one node in the list
    }
    else if(prev_node == NULL) {
        deleteAtHead(head, tail);
    } else if(front == NULL) {
        deleteAtTail(head, tail);
    } else {
        prev_node->next = front;
        front->prev = prev_node;
    }
    free(temp);
}
void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->val << "<-> ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Example usage
    insertAtEnd(head, tail, 10);
    insertAtEnd(head, tail, 20);
    insertAtEnd(head, tail, 30);
    insertAtEnd(head, tail, 40);
    insertAtEnd(head, tail, 50);
    insertAtEnd(head, tail, 60);
    insertAtEnd(head, tail, 70);
    insertAtEnd(head, tail, 80);
    cout << "Original List: ";
    display(head);

    deleteAtHead(head, tail);
    cout << "After deleting head: ";
    display(head);

    deleteAtTail(head, tail);
    cout << "After deleting tail: ";
    display(head);



    deleteAtK(head, tail, 1); // Deleting second node
    cout << "After deleting at position 1: ";
    display(head);

    return 0;
}