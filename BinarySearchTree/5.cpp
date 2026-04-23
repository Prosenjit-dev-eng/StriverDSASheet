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

    TreeNode* findLeftRight(TreeNode* root){
        if(root->right == NULL) return root;
        return findLeftRight(root->right);
    }
    TreeNode* helper(TreeNode* root){
        if(root->left == NULL) return root->right;
        if(root->right == NULL) return root->left;

        TreeNode* rc = root->right;// rc -> right child => 7
        TreeNode* leftRight = findLeftRight(root->left);// 4
        //At last 
        leftRight->right = rc;// 4->7
        return root->left;// 8->3
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key) return helper(root);

        TreeNode* temp = root;
        while(root!=NULL){
            if(root->val > key){
                if(root->left!=NULL && root->left->val == key){
                    root->left = helper(root->left);
                    break; 
                }
                else root = root->left;
            }
            else{
                if(root->right!=NULL && root->right->val == key){
                    root->right = helper(root->right);
                    break; 
                }
                else root = root->right;
            }
        }
        return temp;
    }

int main()
{
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(5);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(7);
    root->left->right->left = new TreeNode(6);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);
    int key = 10;
    root = deleteNode(root, key);
    
    return 0;
}