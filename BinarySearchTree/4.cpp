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
TreeNode* insertRoot(TreeNode* root, int val) {
    if(root == NULL) {
        return new TreeNode(val);
    }
    TreeNode* cur = root;
    while(true){
            if(cur->val <= val){
                // Go to right
                if(cur->right != NULL) cur = cur->right;
                else{
                     cur->right = new TreeNode(val);
                     break;
                }
            }
            else{
                // Go to left
                if(cur->left != NULL) cur = cur->left;
                else{
                     cur->left = new TreeNode(val);
                     break;
                }
            }
    }
    return root;
}
int main()
{
    TreeNode* root = nullptr;
    root = insertRoot(root, 8);
    root = insertRoot(root, 5);
    root = insertRoot(root, 12);
    root = insertRoot(root, 4);
    root = insertRoot(root, 7);
    root = insertRoot(root, 10);
    root = insertRoot(root, 14);
    root = insertRoot(root, 6);
    root = insertRoot(root, 13);
    cout << root->val << endl; // Output the root value to verify
    return 0;
}