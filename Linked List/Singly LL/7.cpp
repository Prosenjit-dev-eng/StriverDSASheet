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
bool palindromeLL(Node* head) {
    if (head == NULL || head->next == NULL) {
        return true; // An empty list or a single node is a palindrome
    }
    // Brute force
//     stack<int> st1;
//     Node* temp = head;
//     while (temp != NULL) {
//         st1.push(temp->data); 
//         temp = temp->next;
//     }
//     while(temp!=NULL){
//         if(st1.top() != temp->data) {
//             return false; // If any mismatch is found, it's not a palindrome
//         }
//         st1.pop(); // Remove the top element from the stack
//         temp = temp->next; // Move to the next node
//     }
//     return true; // If all elements match, it's a palindrome


//      Optimal Approach
//      Case1: Recognise the 2nd half
        Node* fast = head;
        Node* slow = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast ->next->next;
        }
//      Case2: Reverse the 2nd half
        Node* new_head = reverseLL(slow->next);
//      Because slow->next pointing the hlaf's head
//      Case3: Use two pointers
        Node* first = head;
        Node* second = new_head;
        while (second != NULL)
        {
           if (first->data != second->data)
           {
            reverseLL(new_head);
            return false;
           }
           first = first->next;
           second = second->next;

        }
        reverseLL(new_head);
        return true;


}   
int main()
{
    Node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 2);
    insertAtTail(head, 1);
    display(head);
    if (palindromeLL(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }
    return 0;
}