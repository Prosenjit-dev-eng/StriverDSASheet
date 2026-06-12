// Middle of a linked list
#include <iostream>
using namespace std;    
class Node {
public:
    int data;
    Node* next;
    Node (int val){
        data = val;
        next = NULL;
    }

};
void insertAtTail(Node* &head,int val){
    Node* new_node = new Node(val);
    if(head == NULL){
        head = new_node;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    
}
int findLength(Node* head){
    int count = 0;
    Node*temp = head;
    while (temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
// Brute Force
Node* findMiddleNodeOfLL(Node* head){
    int mid = (findLength(head)/2)+1;
    Node* temp = head;
    while (temp!=NULL)
    {
        mid = mid - 1;
        if (mid == 0)
        {
            break;
        }
        temp = temp->next;

    }
    return temp;
}
// Optimized Approach using two pointers
// Slow and Fast Pointer
Node* findMiddleNodeOfLLOptimized(Node* head) {
    if(head == NULL) {
        return NULL; // If the list is empty, return NULL
        }
        Node* slow = head;
        Node* fast = head;
        while (fast != NULL/*Even*/ && fast->next != NULL/*Odd*/) {
            fast = fast->next->next; // Move fast pointer by 2 steps
            slow = slow->next; // Move slow pointer by 1 step
        }
        return slow;
}

void display(Node* &head){
    if (head == NULL)
    {
        return;
    }
    Node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
int  main() {
    Node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    display(head);
    
    Node* middleNode = findMiddleNodeOfLL(head);
    if (middleNode != NULL) {
        cout << "The middle node of the linked list is: " << middleNode->data << endl;
    } else {
        cout << "The linked list is empty." << endl;
    }
    cout << "Optimized Approach: " << endl;
    Node* middleNodeOptimized = findMiddleNodeOfLLOptimized(head);
    if (middleNodeOptimized != NULL) {
        cout << "The middle node of the linked list is: " << middleNodeOptimized->data << endl;
    } else {
        cout << "The linked list is empty." << endl;
    }
    
    return 0;
}
