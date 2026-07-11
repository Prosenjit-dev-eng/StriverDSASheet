#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
// Morris Inorder Traversal
vector<int>inorder(TreeNode* root){
    if(!root) return {};
    vector<int>ans;
    while (root)
    {
        // Left subtree dne
        if(!root->left){
            ans.push_back(root->data);
            root = root->right;
        }
        else
        {
            TreeNode* curr = root->left;
            while (curr->right && curr->right != root)
            {
                curr = curr->right;
            }
            // Left subtree is not traversed
            if(curr->right == NULL){
                curr->right = root;
                root = root->left;
            }
            else
            {
                curr->right = NULL; // remove the pointer
                ans.push_back(root->data);
                root = root->right;
            }
            
            
        }
        
    }
    return ans;
    
}
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(9);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(8);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(6);
    // Inorder
    vector<int>in = inorder(root);
    for(auto i : in) cout<<i<<" ";
    
    return 0;
}