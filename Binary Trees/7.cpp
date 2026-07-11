#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
    bool isSameTree(Node* p, Node* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->data != q->data) return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
int main()
{
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(6);
    root1->right->right = new Node(7);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    root2->right->left = new Node(6);
    root2->right->right = new Node(7);

    cout << isSameTree(root1, root2) << endl; // should print 1 (true)

    return 0;
}