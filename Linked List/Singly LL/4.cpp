#include<bits/stdc++.h>
using namespace std;
// Reverse a linked list
class Node {
public:
    int data;
    Node* next;
    Node (int val){
        data = val;
        next = NULL;
    }

};
void insertAtTail(Node* &head, int val) {
    Node* new_node = new Node(val);
    if(head == NULL) {
        head = new_node;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
Node* reverseLL(Node* &head){
    Node* currptr = head;
    Node* prev = NULL;
    while (currptr!=NULL)
    {
        Node* nextptr = currptr->next;
        currptr->next = prev;
        prev = currptr;
        currptr = nextptr;
    }
    return prev;
}
Node* reverseLLRecursion(Node* &head){

    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    
    // recursive case
    Node* new_head = reverseLLRecursion(head->next);

    // Save a reference to the node following
    // the current 'head' node.
    Node* front = head->next;
    
    // Make the 'front' node point to the current
    // 'head' node in the reversed order.
    front->next = head;
    
    // Break the link from the current 'head' node
    // to the 'front' node to avoid cycles.
    head->next = NULL;
    
    // Return the 'newHead,' which is the new
    // head of the reversed linked list.
    return new_head;


}

void reversePrint(Node* head){
    if (head == NULL) {
        return; // Base case: if the list is empty, do nothing
    }
    reversePrint(head->next); // Recursive call with the next node
    cout << head->data << " "; // Print the current node's data after the recursive call
}
int main()
{
    Node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);          
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    display(head);
    Node* reversedHead = reverseLL(head);
    cout << "Reversed Linked List: ";
    display(reversedHead);


    return 0;
}