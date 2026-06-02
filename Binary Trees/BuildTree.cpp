#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode*left, *right;
    TreeNode(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};
TreeNode* buildTreeFromAnArray(vector<int>&arr){
    if(arr.empty() || arr[0] == -1){
        return NULL;
    }
    queue<TreeNode*>q;
    TreeNode* root = new TreeNode(arr[0]);
    q.push(root);
    int i = 1;
    while (!q.empty() && i < arr.size())
    {
        TreeNode* curr = q.front();
        q.pop();
        if(i < arr.size() && arr[i] != -1){
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
        }
        i++;
        if(i < arr.size() && arr[i] != -1){
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
    
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    TreeNode* root = buildTreeFromAnArray(v);
    
    
}
