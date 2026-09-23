#include<bits/stdc++.h>
using namespace std;
class TreeAncestor {
    
    vector<vector<int>> anchestor;
    int LOG;
public:
    TreeAncestor(int n, vector<int>& parent) {
        LOG = log2(n)+1;
        anchestor.resize(n,vector<int>(LOG));
        // Fill the 0th column according to the question
        for(int node = 0; node < n; node++){
            anchestor[node][0] = parent[node];
        }
        // Column wise traversal
        for(int j = 1; j < LOG; j++){
            for(int node = 0; node < n; node++){
                int mid = anchestor[node][j-1];
                mid == -1 ? -1 : anchestor[node][j] =  anchestor[mid][j-1]; 
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int j = 0; j < LOG; j++){
            if(k & (1 << j)){
                node = anchestor[node][j];
                if(node == -1) return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
int main()
{
    return 0;
}