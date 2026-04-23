#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
    int maxpath(Node* root, int &maxi){
        if(!root) return 0;
        // int lh = maxpath(root->left,maxi);       
        // int rh = maxpath(root->right,maxi);// This is not done
        // But here we have to neglect negative numbers
        int lh = max(0,maxpath(root->left,maxi));       
        int rh = max(0,maxpath(root->right,maxi)); //'-'ve = return 0
        // Store maxPath
        maxi = max(maxi,root->data+lh+rh);

        return root->data+max(lh,rh);
    }
    int maxPathSum(Node* root) {
        int maxi = INT_MIN;// We can't take maxi = 0, bcz sum could be negative
        maxpath(root,maxi);
        return maxi;
    }
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout << "Max Path Sum: " << maxPathSum(root) << endl;
    return 0;
}
