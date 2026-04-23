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
vector<int> iterativePreorder(Node*root){
    vector<int>ans;
    if(!root) return ans;

    stack<Node*>st;
    st.push(root);
    while (!st.empty())
    {
        root = st.top();
        st.pop();
        ans.push_back(root->data);
        if(root->right) st.push(root->right);
        if(root->left) st.push(root->left);
 
    }
    return ans;
}
vector<int> iterativeInorder(Node*root){
    vector<int>ans;

    stack<Node*>st;
    Node* curr = root;
    while (true)
    {
        if(curr != NULL){
            st.push(curr);
            curr = curr->left;

        }
        else
        {
            if(st.empty()) break;
            curr = st.top();
            st.pop();
            ans.push_back(curr->data);
            curr = curr->right;
        }
        
    }
    return ans;
}
vector<int> iterativePostorder(Node*root){
    vector<int>ans;

    stack<Node*>st;
    Node* curr = root;
    while (true)
    {
        if(curr != NULL){
            st.push(curr);
            curr = curr->left;

        }
        else
        {
            if(st.empty()) break;
            curr = st.top();
            ans.push_back(curr->data);
            curr = curr->right;
            st.pop();
        }
        
    }
    return ans;
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


    vector<int>res = iterativePreorder(root);
    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    vector<int>in = iterativeInorder(root);
    for (int i = 0; i < in.size(); i++)
    {
        cout<<in[i]<<" ";
    }
    cout<<endl;
    vector<int>post = iterativePostorder(root);
    for (int i = 0; i < post.size(); i++)
    {
        cout<<post[i]<<" ";
    }
    cout<<endl;
    return 0;
}