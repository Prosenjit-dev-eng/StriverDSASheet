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
class Solution {
public:
    void solve(TreeNode* root, int &cnt, int &ans, int k) {
        if (root == NULL) return;

        // Right -> Root -> Left
        solve(root->right, cnt, ans, k);

        cnt++;
        if (cnt == k) {
            ans = root->val;
            return;
        }

        solve(root->left, cnt, ans, k);
    }

    int kthLargest(TreeNode* root, int k) {
        int cnt = 0;
        int ans = -1;
        solve(root, cnt, ans, k);
        return ans;
    }
    void solveS(TreeNode* root, int &cnt, int &ans, int k) {
        if (root == NULL) return;

        // Left -> Root -> Right
        solveS(root->left, cnt, ans, k);

        cnt++;
        if (cnt == k) {
            ans = root->val;
            return;
        }

        solveS(root->right, cnt, ans, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int ans = -1;
        solveS(root, cnt, ans, k);
        return ans;
    }
};
int main()
{
    return 0;
}