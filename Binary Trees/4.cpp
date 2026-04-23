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
int height(Node* root){
    if(!root) return 0;
     int lh = height(root->left);
     int rh = height(root->right);
     
     if(lh == -1 && rh == -1) return -1;// Change
     if(abs(lh-rh)<=1) return -1;

     return 1+max(lh,rh);// 1+ for the top

}
bool isBalenced(Node* root){
 return (height(root)) != -1;
    
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

    if (isBalenced(root))
    {
        cout<<"True, This is a B.T"<<endl;
    }
    else
    {
        cout<<"True, This is a B.T"<<endl;
        
    }
    
    

    return 0;
}