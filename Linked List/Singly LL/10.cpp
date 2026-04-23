#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    string s1 = "", s2 = "";
    while (l1!=NULL)
    {
        s1 += l1->val;
        l1 = l1->next;
    }
    while (l2!=NULL)
    {
        s2 += l2->val;
        l2 = l2->next;
    }
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int n1 = stoi(s1);
    int n2 = stoi(s2);
    int sum = n1 + n2;
    string s3 = to_string(sum);
    reverse(s3.begin(), s3.end());
    ListNode* head = new ListNode(s3[0]-'0');
    ListNode* temp = head;
    for (int i = 1; i < s3.size(); i++)
    {
        temp->next = new ListNode(s3[i]-'0');
        temp = temp->next;
    }
    return head;
    
}
int main()
{
    return 0;
}