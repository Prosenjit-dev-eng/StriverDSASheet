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
int widthOfBinaryTree(TreeNode* root) {
    if(!root) return {};
    int maxWidth = INT_MIN;
    queue<pair<TreeNode*,int>>q;// {node,index}
    q.push({root,0});
    while (!q.empty())
    {
        int l = q.front().second;
        int r = q.back().second;
        maxWidth = max(maxWidth,r - l + 1);
        int n = q.size();
        while (n--)
        {
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int idx = it.second;
            if(node->left) q.push({node->left,2*idx+1});
            if(node->right) q.push({node->right,2*idx+2});

        }
        
    }
    return maxWidth;
}
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->left->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    root->right->right->left = new TreeNode(7);
    cout<<widthOfBinaryTree(root)<<endl;
    return 0;
}