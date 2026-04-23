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
bool cycleDetection(Node* head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }
    unordered_map<Node*, int> mpp;
    Node* temp = head;
    while (temp!=NULL)
    {
        if (mpp.find(temp) != mpp.end()) {
            return true; // Cycle detected
        }
        mpp[temp] = 1; // Mark this node as visited
        temp = temp->next; // Move to the next node
    }
    

    Node* slow = head;
    Node* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next; // Move slow by 1 step
        fast = fast->next->next; // Move fast by 2 steps
        
         if (slow == fast) {
             return true; // Cycle detected
         }
     }
     return false; // No cycle detected
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
    if (cycleDetection(head)) {
        cout << "Cycle detected in the linked list." << endl;
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }      
    return 0;
}