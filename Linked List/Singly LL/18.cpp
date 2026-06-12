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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        int n = 1;
        ListNode* temp = head;
        while(temp->next != NULL) {
            n++;
            temp = temp->next;
        }
        k = k%n;
        if(k == 0) return head;
        temp -> next = head;
        int steps = n - k - 1;
        ListNode* newTail = head;
        for(int i = 0; i < steps; i++){
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;
        newTail->next = NULL;
        return newHead;
    }
int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int k = 2;
    ListNode* newHead = rotateRight(head, k);
    while (newHead != NULL)
    {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    
    return 0;
}