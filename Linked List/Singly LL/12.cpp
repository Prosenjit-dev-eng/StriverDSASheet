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
ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyNode = new ListNode(-1);//The dummy node is used to handle edge cases uniformly, especially when the node to be deleted is the head node.
        dummyNode->next = head;
        ListNode* f = dummyNode;
        for(int i = 0; i <= n; i++){
            f = f->next;// f moves to the previous of the required node
        }
        ListNode* s = dummyNode;
        while(f != NULL){
            s = s->next;
            f = f->next;
        }
        ListNode* delNode = s->next;
        s->next = s->next->next;
        delete delNode;
        return dummyNode->next;
}
int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int n = 2;
    head = removeNthFromEnd(head, n);
    while (head!=NULL)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    return 0;
}