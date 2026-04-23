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
vector<int>topview(TreeNode* root){
    vector<int>ans;
    if(!root) return ans;
    map<int,int>mp; // line & node value
    queue<pair<TreeNode*,int>>q; // node, line
    q.push({root,0});
    while(!q.empty()){
        auto temp = q.front();// Or pair<TreeNode*, int>
        q.pop();
        TreeNode* frontNode = temp.first;
        int line = temp.second;
        // If this line is not already present in the map
        if(mp.find(line) == mp.end()){
            mp[line] = frontNode->val;
        }
        if(frontNode->left) q.push({frontNode->left, line-1});
        if(frontNode->right) q.push({frontNode->right, line+1});
    }
    // Extracting values from the map in sorted order of lines
    for(auto it : mp){
        ans.push_back(it.second);
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
    vector<int> result = topview(root);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}