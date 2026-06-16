#include<bits/stdc++.h>
using namespace std;
class ListNode {
    public:
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
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
    int pairSum(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast!=NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* midNextReverse = reverseLL(slow);
        ListNode*t1 = head, *t2 = midNextReverse;
        int maxi = 0;
        while (t1!=NULL && t2!=NULL)
        {
            int sum = t1->val+t2->val;
            maxi = max(maxi,sum);
            t1 = t1->next;
            t2 = t2->next;
        }
        return maxi;
        
    }

int main()
{
    ListNode* head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    cout<<pairSum(head)<<endl;
    return 0;
}