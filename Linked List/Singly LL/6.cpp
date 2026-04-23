#include<bits/stdc++.h>
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
Node* cycleDetection(Node* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next; // Move slow by 1 step
        fast = fast->next->next; // Move fast by 2 steps
        
        if (slow == fast) {
            slow = head; // Move slow to the head
            while (slow != fast) {
                slow = slow->next; // Move slow by 1 step
                fast = fast->next; // Move fast by 1 step
            }
        }
        return slow; // Cycle detected, return the starting point of the cycle
    }
    return NULL; // No cycle detected
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
    // Creating a cycle for testing
    head->next->next->next->next->next = head->next; // 5 -> 2 creates a cycle
    Node* startingpoint = cycleDetection(head);
    if (startingpoint) {
        cout << "Cycle detected in the linked list at node with value: " << startingpoint->data << endl;
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }    
    return 0;
}