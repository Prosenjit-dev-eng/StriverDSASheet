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
int findFloor(TreeNode* root, int key){
    int floor = -1;
    while(root){
        if(root->val == key){
            floor = root->val;
            return floor;
        }
        if(root->val > key){
            root = root->left;
        }
        else{
            floor = root->val;// floor is less than equal to key
            root = root->right;
        }
    }
    return floor;
}
int main()
{
    // 8 5 12 4 7 10 14 -1 -1 6 -1 -1 -1 13, Key = 9
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(5);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(7);
    root->left->right->left = new TreeNode(6);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);
    int key = 9;
    int floor = findFloor(root, key);
    if(floor != -1) cout << "Floor of " << key << " is " << floor << endl;
    else cout << "No Floor found for " << key << endl;
    return 0;
}