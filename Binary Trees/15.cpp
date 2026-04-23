#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode*left,*right;
    TreeNode(int x): val(x),left(NULL),right(NULL){}
};
bool getPath(TreeNode* root, vector<TreeNode*>&a, int x){
    if(!root) return NULL;
    a.push_back(root);
    if(root->val == x) return true;
    if(getPath(root->left,a,x) || getPath(root->right,a,x)) return true;
    a.pop_back();
    return false;
}
vector<TreeNode*>path(TreeNode* root, int x){
    vector<TreeNode*>r;
    getPath(root,r,x);
    return r;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>p1 = path(root,p->val);
        vector<TreeNode*>p2 = path(root,q->val);
        int i = 0;
        TreeNode* lca = NULL;
        while(i < p1.size() && i < p2.size()){
            if(p1[i] == p2[i]) lca = p1[i];
            else break;
            i++;
        }
        return lca;
}
TreeNode* treeBuilder(vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return NULL;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < arr.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // Left child
        if (i < arr.size() && arr[i] != -1) {
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
        }
        i++;

        // Right child
        if (i < arr.size() && arr[i] != -1) {
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}
int main()
{
    // Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
    vector<int>arr = {3,5,1,6,2,0,8,-1,-1,7,4};
    TreeNode* root = treeBuilder(arr);
    TreeNode* p = root->left; // Node with value 5
    TreeNode* q = root->left->right->right; // Node with value 4
    TreeNode* lca = lowestCommonAncestor(root, p, q);
    if (lca) {
        cout << "Lowest Common Ancestor: " << lca->val << endl; // Should output 5
    } else {
        cout << "Lowest Common Ancestor not found." << endl;
    }
    return 0;
}