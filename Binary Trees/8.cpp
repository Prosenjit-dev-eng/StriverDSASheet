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

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;// true = left to right, false = right to left
        while(!q.empty()){
            int size = q.size();   // number of nodes in this level
            vector<int> row(size);     // collect this level’s nodes

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front(); q.pop();

                int idx = (flag)? i :  (size - i - 1);//(size - i - 1) means from back side
                row[idx] = curr->val;
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            // After this level
            flag = !flag;// VVI
            ans.push_back(row);  // add completed level
        }
        return ans;
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

    vector<vector<int>> result = zigzagLevelOrder(root);
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}