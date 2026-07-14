#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};


void preorder(Node* root, int key, Node*& pre, Node*& suc) {
    if (root == nullptr) return;

    if (root->data < key && (pre == nullptr || pre->data < root->data)) {
        pre = root;
    }

    if (root->data > key && (suc == nullptr || suc->data > root->data)) {
        suc = root;
    }

    preorder(root->left, key, pre, suc);
    preorder(root->right, key, pre, suc);
}


vector<Node*> findPreSuc(Node* root, int key) {
    Node* pre = nullptr;
    Node* suc = nullptr;
    preorder(root, key, pre, suc);
    return {pre, suc};
}

int main() {
    // Create BST:
    //      50 
    //     /  \
    //   30     70
    //   / \    / \
    // 20  40  60  80

    int key = 65;
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    vector<Node*> result = findPreSuc(root, key);
    Node* pre = result[0];
    Node* suc = result[1];

    cout << (pre ? to_string(pre->data) : "NULL") << " ";
    cout << (suc ? to_string(suc->data) : "NULL") << endl;
}
