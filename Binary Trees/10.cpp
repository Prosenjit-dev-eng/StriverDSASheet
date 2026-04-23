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
vector<vector<int>> verticalTraversal(TreeNode* root) {
        // map: hd -> (level -> vector of values)
        map<int, map<int, vector<int>>> nodes;
        // queue for BFS: stores node and its (hd, level)
        queue<pair<TreeNode*, pair<int,int>>> q;
        
        vector<vector<int>> ans;
        if(!root) return ans;
        
        q.push({root, {0,0}});
        
        while(!q.empty()) {
            auto temp = q.front();
            q.pop();   // ✅ important, otherwise infinite loop
            
            TreeNode* frontNode = temp.first;
            int hd = temp.second.first;   // horizontal distance
            int lvl = temp.second.second; // depth level
            
            nodes[hd][lvl].push_back(frontNode->val);
            
            if(frontNode->left) 
                q.push({frontNode->left, {hd-1, lvl+1}});
                
            if(frontNode->right) 
                q.push({frontNode->right, {hd+1, lvl+1}});
        }
        
        // build result
        for (auto &i : nodes) {              // each vertical column
            vector<int> col;
            for (auto &j : i.second) {       // each level in that column
                auto vals = j.second;
                sort(vals.begin(), vals.end()); // tie-breaker
                for (int v : vals) {
                    col.push_back(v);
                }
            }
            ans.push_back(col);
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
    vector<vector<int>> result = verticalTraversal(root);
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}