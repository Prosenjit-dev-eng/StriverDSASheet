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
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* curr = dummyNode;
        int carry = 0;
        while(t1 || t2 || carry){
            int sum = carry;
            if(t1){
                sum += t1->val;
                t1 = t1->next;
            }
            if(t2){
                sum += t2->val;
                t2 = t2->next;
            }
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }
        return dummyNode->next;
}
int main()
{
    ListNode* head1 = new ListNode(2);
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(3);
    ListNode* head2 = new ListNode(5);
    head2->next = new ListNode(6);
    head2->next->next = new ListNode(4);
    ListNode* head = addTwoNumbers(head1, head2);
    while (head!=NULL)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    return 0;
}