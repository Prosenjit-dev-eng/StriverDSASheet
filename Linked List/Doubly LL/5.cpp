#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node*prev;
    Node*next;
    Node(int data){
        val = data;
        prev = NULL;
        next = NULL;
    }

};
void deleteAtHead(Node* &head, Node* &tail){
    if(head == NULL) return; // List is empty
    Node* temp = head;
    head = head->next;
    if(head != NULL) {
        head->prev = NULL;
    } else {
        tail = NULL; // If the list becomes empty
    }
    free(temp);
}
void deleteAtTail(Node* &head, Node* &tail){
    if(tail == NULL) return; // List is empty
    Node* temp = tail;
    tail = tail->prev;
    if(tail != NULL) {
        tail->next = NULL;
    } else {
        head = NULL; // If the list becomes empty
    }
    free(temp);
}
vector<pair<int,int>> findpairs(Node* &head, int target){
    vector<pair<int,int>>ans;
    Node*temp1 = head;
    while (temp1->next!=NULL)
    {
        temp1 = temp1->next;
    }
    Node* last = temp1;
    Node*first = head;
    while (first->val < last->val)
    {
        if ((first->val+last->val)==target)
        {
            ans.push_back({first->val,last->val});
        }
        first = first->next;
        last = last->prev;
    }
    return ans;
}

void insertAtStart(Node* &head, Node* &tail,int val){
    Node* new_node = new Node(val);
    if(head == NULL){
        head = new_node;
        tail = new_node;
        return;
    }
    else{
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }

}
void display(Node* head){
    Node* temp = head;
    while (temp!=NULL)
    {
        cout<<temp->val<<"<->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;

}
int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertAtStart(head, tail, 90);
    insertAtStart(head, tail, 40);
    insertAtStart(head, tail, 30);
    insertAtStart(head, tail, 20);
    insertAtStart(head, tail, 10);

    cout << "Original List: "; 
    display(head);
    int target = 100;
    vector<pair<int, int>>ans = findpairs(head, target);
    for(auto &itr: ans){
        cout<<"Pairs: "<<itr.first<<","<<itr.second<<endl;
    }
    return 0;
}