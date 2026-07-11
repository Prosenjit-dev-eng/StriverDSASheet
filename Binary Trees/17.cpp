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
vector<int> leftView(TreeNode *root) {
        if(!root) return {};
        vector<int>ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s; i++){
                TreeNode * n = q.front();
                q.pop();
                
                if(i == 0) ans.push_back(n->val);
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
        }
        return ans;
    }
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);        
    root->right = new TreeNode(3);
    vector<int> ans = leftView(root);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}