#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    void dfs(Node* node, Node* cloneNode,unordered_map<Node*,Node*>&mp){
        for(Node* neigh : node->neighbors){
            if(mp.find(neigh) == mp.end()){
                Node* cloneNeigh = new Node(neigh->val);
                mp[neigh] = cloneNeigh;
                cloneNode->neighbors.push_back(cloneNeigh);
                dfs(neigh,cloneNeigh,mp);
            }
            else cloneNode->neighbors.push_back(mp[neigh]);
        }
    }

    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        Node*cloneNode = new Node(node->val);
        unordered_map<Node*,Node*>mp;
        mp[node] = cloneNode;
        dfs(node,cloneNode,mp);
    }
};
int main()
{
    return 0;
}