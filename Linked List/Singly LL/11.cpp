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
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dnode = new ListNode(-1);
    ListNode* temp = dnode;
    ListNode* t1 = list1;
    ListNode* t2 = list2;
    while (t1!=NULL && t2!=NULL)
    {
        if (t1->val<t2->val)
        {
            temp->next = t1;
            temp = temp->next;
            t1 = t1->next;
        }
        else
        {
            temp->next = t2;
            temp = temp->next;
            t2 = t2->next;
        }
    
    }
    if(t1==NULL) temp->next = t2;
    else temp->next = t1;
    return dnode->next;
}
int main()
{
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(4);
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(4);
    ListNode* head = mergeTwoLists(head1, head2);
    while (head!=NULL)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    return 0;
}