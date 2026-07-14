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
class BSTIterator {
    stack<TreeNode*>st;
    bool rev;
    void storeNodes(TreeNode* root){
        while(root){
            st.push(root);
            if(rev) root = root->right;// Reverse inorder traversal
            else root = root->left;
        }
    }
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        rev = isReverse;
        storeNodes(root);
    }
    
    int next() {
        TreeNode* cur = st.top();
        st.pop();
        if(!rev) storeNodes(cur->left);
        else storeNodes(cur->right);
        return cur->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
bool findTarget(TreeNode* root, int k) {
    if(!root) return false;
    BSTIterator l(root, false);
    BSTIterator r(root, true);
    int i = l.next();
    int j = r.next();
    while(i < j){
        if(i + j == k) return true;
        else if(i + j < k) i = l.next();
        else j = r.next();
    }
    return false;
}
int main()
{
    return 0;
}