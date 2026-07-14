#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;    
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p) {
    TreeNode* pred = NULL;

    while (root) {
        if (p->val > root->val) {
            pred = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }

    return pred;
}
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* succ = NULL;

    while (root) {
        if (p->val < root->val) {
            succ = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return succ;
}
int main()
{
    return 0;
}