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
int height(Node* root,int& dia){
    if(!root) return 0;
     int lh = height(root->left,dia);
     int rh = height(root->right,dia);

    dia = max(dia,lh+rh);
     
     return 1+max(lh,rh);// 1+ for the top

}
int diameter(Node*root){
    int dia = 0;
    height(root,dia);
    return dia;
}




int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<<diameter(root)<<endl;
    return 0;
}