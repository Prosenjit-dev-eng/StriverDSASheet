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

bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return true; // If the list is empty, return NULL
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next->next != NULL/*Even*/ && fast->next != NULL/*Odd*/) {
            // fast->next->next? => coz it for even length linkedlists usually it ids fast->next but here it 
            // to find the exactmidddle 6/2 == 3, ussually we return 4
            slow = slow->next; // Move slow pointer by 1 step
            fast = fast->next->next; // Move fast pointer by 2 steps
        }
        ListNode* second = reverseLL(slow->next);
        ListNode* p1 = head;
        ListNode* p2 = second;
        while (p2)
        {
            if(p1->val != p2->val) return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
        
}
int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    cout<<isPalindrome(head)<<endl;
    return 0;
}