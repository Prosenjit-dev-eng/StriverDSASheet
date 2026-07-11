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
int pi;
TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int start, int end){
    if(start > end) return NULL;
    int val = preorder[pi];
    pi++;
    TreeNode* root = new TreeNode(val);
    int i = start;
    for (; i <= end; i++)
    {
        if(val == inorder[i])
        {
            break;
        }
    }
    root->left = helper(preorder,inorder, start, i - 1);
    root->right = helper(preorder, inorder, i + 1, end);
    return root;
    
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    pi = 0;
    int n = inorder.size();
    return helper(preorder,inorder,0,n-1);
}

int main()
{
    vector<int>preorder = {3,9,20,15,7};
    vector<int>inorder = {9,3,15,20,7};
    
    return 0;
}