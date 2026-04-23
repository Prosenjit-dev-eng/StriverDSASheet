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
bool isLeaf(TreeNode* node) {
    return node != nullptr && node->left == nullptr && node->right == nullptr;
}

void addLeftBoundary(TreeNode* root, vector<int> &res){
    TreeNode* curr = root;
    while (curr) {
        if (!isLeaf(curr)) res.push_back(curr->val);
        curr = curr->left ? curr->left : curr->right;
    }
}
void addLeaves(TreeNode* root, vector<int> &res){
    if (isLeaf(root)) {
        res.push_back(root->val);
        return;
    }
    if (root->left) addLeaves(root->left, res);
    if (root->right) addLeaves(root->right, res);
}
void addRightBoundary(TreeNode* root, vector<int> &res){
    TreeNode* curr = root;
    stack<int>st;
    while (curr) {
        if (!isLeaf(curr)) st.push(curr->val);
        curr = curr->right ? curr->right : curr->left;
    }
    // Add right boundary in reverse order
    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
}
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> result;
    addLeftBoundary(root, result);
    addLeaves(root, result);
    addRightBoundary(root, result);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}