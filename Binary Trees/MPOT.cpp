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
// Morris Postorder Traversal
vector<int>postorder(TreeNode* root){
    if(!root) return {};
    vector<int>ans;
    while (root)
    {
        // right subtree dne
        if(!root->right){
            ans.push_back(root->data);
            root = root->left;
        }
        else
        {
            TreeNode* curr = root->right;
            while (curr->left && curr->left != root)
            {
                curr = curr->left;
            }
            // Left subtree is not traversed
            if(curr->left == NULL){
                ans.push_back(root->data);
                curr->left = root;
                root = root->right;
            }
            else
            {
                curr->left = NULL; // remove the pointer
                root = root->left;
            }
            
        }
        
    }
    reverse(ans.begin(),ans.end());
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
    vector<int>in = postorder(root);
    for(auto i : in) cout<<i<<" ";
    
    return 0;
}