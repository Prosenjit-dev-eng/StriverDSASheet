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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        ListNode* t1 = headA;
        ListNode* t2 = headB;

        while (t1!=t2)
        {
            t1 = t1->next;
            t2 = t2->next;
            if(t1 == t2) return t1;
            if(!t1) t1 = headB;
            if(!t2) t2 = headA;
        }
           
        return t1;
    }
int main()
{
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(0);
    headB->next->next = new ListNode(1);
    ListNode* common = new ListNode(8);
    headA->next->next = common;
    headB->next->next->next = common;
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);
    ListNode* ans = getIntersectionNode(headA, headB);
    if(ans) cout<<ans->val;
    else cout<<"No intersection";
    return 0;
}