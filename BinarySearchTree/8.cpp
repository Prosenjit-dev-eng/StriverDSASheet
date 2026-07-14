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
bool isValid(TreeNode* root, long long min, long long max) {
        if (!root) return true;

        // Check current node is within range
        if (root->val <= min || root->val >= max)
            return false;

        return isValid(root->left, min, root->val) &&
               isValid(root->right, root->val, max);
}

bool isValidBST(TreeNode* root) {
        return isValid(root, LLONG_MIN, LLONG_MAX);
}
int main()
{
    return 0;
}