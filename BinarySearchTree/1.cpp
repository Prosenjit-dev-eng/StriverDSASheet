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
TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=NULL && root->val!=val){
            root = val < root->val ? root->left : root->right;
        }
        return root;
    }
int main()
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    int val = 2;
    TreeNode* ans = searchBST(root,val);
    if(ans!=NULL) cout << ans->val << endl;
    else cout << "Value not found" << endl;
    return 0;
}