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
        if(!p && !q) return true;   // both null
        if(!p || !q) return false;  // one null, one not

        queue<Node*> q1, q2;
        q1.push(p);
        q2.push(q);

        while(!q1.empty() && !q2.empty()){
            Node *curr1 = q1.front(); q1.pop();
            Node *curr2 = q2.front(); q2.pop();

            if(curr1->data != curr2->data) return false;

            // left check
            if((curr1->left && !curr2->left) || (!curr1->left && curr2->left))
                return false;
            if(curr1->left && curr2->left){
                q1.push(curr1->left);
                q2.push(curr2->left);
            }

            // right check
            if((curr1->right && !curr2->right) || (!curr1->right && curr2->right))
                return false;
            if(curr1->right && curr2->right){
                q1.push(curr1->right);
                q2.push(curr2->right);
            }
        }

        return q1.empty() && q2.empty(); // both queues exhausted
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