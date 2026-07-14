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
class Info{
    public:
    int mn,mx,sz;
    Info(int mn,int mx,int sz){
        this->mn=mn;
        this->mx=mx;
        this->sz=sz;
    }
};
Info helper(TreeNode* root){
    if(!root) return Info{INT_MAX,INT_MIN,0};// Leaf Node
    // Here at second we have the maximum
    Info l = helper(root->left);
    Info r = helper(root->right);
    // check root->data should be greater than left subtree's maximum(Inorder precedessor) and smaller than right subtree's minimum(Inorder successor)
    if(root->val > l.mx && root->val < r.mn){
        int curMin = min(root->val, l.mn);
        int curMax = max(root->val, r.mx);
        int curSize = l.sz+r.sz+1;
        return Info(curMin,curMax,curSize);

    }
    else return Info(INT_MIN,INT_MAX,max(l.sz,r.sz));

}
int LargestBST(TreeNode* root) {
    Info ans = helper(root);
    return ans.sz;
    
}
int main()
{
    return 0;
}