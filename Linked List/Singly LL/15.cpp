#include<bits/stdc++.h>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode*next;
    ListNode(int data){
        val = data;
        next = NULL;
    }
};
ListNode* reverseLL(ListNode* &head){
    ListNode* currptr = head;
    ListNode* prev = NULL;
    while (currptr!=NULL)
    {
        ListNode* nextptr = currptr->next;
        currptr->next = prev;
        prev = currptr;
        currptr = nextptr;
    }
    return prev;
}
ListNode* getKthNode(ListNode* head, int k){
    k -= 1;
    ListNode* temp = head;
    while (temp!=NULL && k > 0)
    {
        temp = temp->next;
        k--;
    }
    return temp;
}
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* temp = head;
    ListNode* prev = NULL;
    while (temp!=NULL)
    {
        ListNode* kthNode = getKthNode(temp,k);
        if(!kthNode){
            if(prev) prev->next = temp;
            break;
        }
        ListNode* nextNode = kthNode->next;
        kthNode->next = NULL;
        reverseLL(temp);
        if(temp == head) head = kthNode;
        else prev->next = kthNode;
        prev = temp;
        temp = nextNode;
    }
    return head;
}
int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);
    head->next->next->next->next->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next->next->next->next->next = new ListNode(10);
    int k = 3;
    ListNode* ans = reverseKGroup(head,k);
    ListNode* temp = ans;
    while (temp!=NULL)
    {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return 0;
}