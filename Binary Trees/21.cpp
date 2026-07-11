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
int po;
TreeNode* helper(vector<int>& postorder, vector<int>& inorder, int start, int end){
    if(start > end) return NULL;
    int val = postorder[po];
    po--;
    TreeNode* root = new TreeNode(val);
    int i = start;// in inorder
    for (; i <= end; i++)
    {
        if(val == inorder[i])
        {
            break;
        }
    }
    root->right = helper(postorder, inorder, i + 1, end);
    root->left = helper(postorder,inorder, start, i - 1);
    return root;
    
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    po = postorder.size() - 1;
    int n = inorder.size();
    return helper(postorder,inorder,0,n-1);
}
int main()
{
    return 0;
}