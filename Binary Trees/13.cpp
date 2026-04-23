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
vector<int>rightview(TreeNode* root){
    vector<int>ans;
    if(!root) return ans;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            TreeNode* frontNode = q.front();
            q.pop();
            if(i==n-1) ans.push_back(frontNode->val);
            if(frontNode->left) q.push(frontNode->left);
            if(frontNode->right) q.push(frontNode->right);
        }
    }
    return ans;
}
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);        
    root->right = new TreeNode(3);
    vector<int> ans = rightview(root);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}