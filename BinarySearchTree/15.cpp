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
    void storeLeftNodes(TreeNode* root){
        while(root){
            st.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        storeLeftNodes(root);
    }
    
    int next() {
        TreeNode* cur = st.top();
        st.pop();
        storeLeftNodes(cur->right);
        return cur->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
int main()
{
    return 0;
}