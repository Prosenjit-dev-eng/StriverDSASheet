// Structure in c++
#include<iostream>
#include<queue>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
// DFs
void inorder(Node*root){
    // left->root->right
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";// so root at the middle;
    inorder(root->right);
}
void preorder(Node*root){
    // root->left->right
    
    if(!root) return;
    cout<<root->data<<" ";// so at the start
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node*root){
    // left->right->root
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";// so root at the end;
}
// BFS
void levelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front(); q.pop();
        cout << curr->data << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->right = new Node(7);
    root->left->right = new Node(4);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(6);

    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    levelOrder(root);
    cout<<endl;


}