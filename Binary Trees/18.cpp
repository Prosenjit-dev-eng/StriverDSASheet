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
vector<vector<int>> preInPostTraversal(TreeNode* root){
    if(!root) return {};
    stack<pair<TreeNode*,int>>st;//TreeNode, value
    vector<int>pre,in,post;
    st.push({root,1});
    while (!st.empty())
    {
        auto it = st.top();
        st.pop(); 
        if(it.second == 1){
            pre.push_back(it.first->val);
            it.second = 2;
            st.push(it);
            if (it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        }
        else if (it.second == 2)
        {
            in.push_back(it.first->val);
            it.second = 3;
            st.push(it);
            if(it.first->right != NULL) st.push({it.first->right,1});
        }
        else{
            post.push_back(it.first->val);
        }
        
    }
    vector<vector<int>> res;
    res.push_back(pre);
    res.push_back(in);
    res.push_back(post);
    return res;

}
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    vector<vector<int>> res = preInPostTraversal(root);
    for(auto& r : res){
        for(auto& a : r){
            cout<<a<<" ";
        }
        cout<<endl;
    }
    return 0;
}