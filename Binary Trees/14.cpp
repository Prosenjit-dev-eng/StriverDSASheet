#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode*left,*right;
    TreeNode(int x): val(x),left(NULL),right(NULL){}
};
bool getPath(TreeNode* root, vector<int>&arr, int x){
    if(!root) return false;
    arr.push_back(root->val);
    if (root->val == x)
    {
        return true;
    }
    if (getPath(root->left,arr,x) || getPath(root->right,arr,x))
    {
        return true;
    }
    // If not found, backtrack and remove current node
    arr.pop_back();
    return false;
    
}
vector<int>path(TreeNode* root, int x){
    vector<int>res;
    if(!root) return res;
    getPath(root,res,x);
    return res;
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
    vector<int>arr = {1, 2, 3, -1, -1, 4, 5, -1, -1, 6};
    TreeNode* root = treeBuilder(arr);
    vector<int>res = path(root,6);
    for(int r : res){
        cout<<r<<"->";
    }
    
    return 0;
}