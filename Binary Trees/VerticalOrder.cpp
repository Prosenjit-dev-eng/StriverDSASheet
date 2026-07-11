#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int,int> P;
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
vii verticalOrder(TreeNode*root){
    map<int,map<int,multiset<int>>> nodes;// vertical, level, node->data
    queue<pair<TreeNode*,P>>q;// root,vertical,level
    q.push({root,{0,0}});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();

        TreeNode* node = p.first;
        int vertical = p.second.first;
        int level = p.second.second;

        nodes[vertical][level].insert(node->data);

        if(node->left) q.push({node->left,{vertical-1,level+1}});
        if(node->right) q.push({node->right,{vertical+1,level+1}});

    }
    // Put the elements into the vector
vii ans;

for (auto &vertical : nodes) {
    vi col;

    for (auto &level : vertical.second) {
        for (int value : level.second) {
            col.push_back(value);
        }
    }

    ans.push_back(col);
}

return ans;
}
int main()
{
    return 0;
}