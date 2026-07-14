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
    int mn,mx,sum;
    Info(int mn, int mx, int sum){
        this->mn=mn;
        this->mx=mx;
        this->sum=sum;
    }

};
int ans = 0;
Info helper(TreeNode* root){
    if(!root) return Info(INT_MAX, INT_MIN,0);
    Info l = helper(root->left);
    Info r = helper(root->right);
    if(root->val > l.mx && root->val < r.mn){
        int curMin = min(root->val, l.mn);
        int curMax = max(root->val, r.mx);
        int curSum = l.sum+r.sum+root->val;
        ans = max(ans,curSum);
        return Info(curMin,curMax,curSum);
    } 
    else return Info(INT_MIN, INT_MAX,0);
}
int maxSumBST(TreeNode* root) {
    Info in = helper(root);
    return ans;
}
int main()
{
    return 0;
}