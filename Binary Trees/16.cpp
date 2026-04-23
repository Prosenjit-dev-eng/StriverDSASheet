#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode*left,*right;
    TreeNode(int x): val(x),left(NULL),right(NULL){};
};
TreeNode* treeBuilder(vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return NULL;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < arr.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // Left child
        if (i < arr.size() && arr[i] != -1) {
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
        }
        i++;

        // Right child
        if (i < arr.size() && arr[i] != -1) {
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}
void flatten(TreeNode* root) {
        if(root == NULL) return;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();
            if(curr->right) st.push(curr->right);
            if(curr->left) st.push(curr->left);
            if(!st.empty()) curr->right = st.top();
            curr->left = NULL;
        }
}
int main()
{
    //  root = [1,2,5,3,4,null,6]
    vector<int>arr = {1,2,5,3,4,-1,6};
    TreeNode* root = treeBuilder(arr);
    flatten(root);
    return 0;
}