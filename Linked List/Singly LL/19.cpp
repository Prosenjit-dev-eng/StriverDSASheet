#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    // Insert nodes in between
   Node* temp = head;     
   while (temp!=NULL)
   {
    Node*copyNode = new Node(temp->val);
    copyNode->next = temp->next;
    temp->next = copyNode;
    temp = temp->next->next;
   }
   // Connect random pointers
    temp = head;     
   while (temp!=NULL)
   {
    Node*copyNode = temp->next;
    if(temp->random) copyNode->random = temp->random->next;
    temp = temp->next->next;
   } 
   // Connect next pointer
    temp = head;  
    Node* dnode = new Node(-1);   
    Node* res = dnode;   

   while (temp!=NULL)
   {
    res->next = temp->next;
    temp->next = temp->next->next;

    res = res->next;
    temp = temp->next;
   } 
   return dnode->next;
}
int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->random = head->next;
    Node* copyHead = copyRandomList(head);
    cout<<copyHead->val<<" "<<copyHead->random->val;
    return 0;
}