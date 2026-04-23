#include<bits/stdc++.h>
using namespace std;
bool dfs(int u, int parent, vector<bool>&vis, vector<vector<int>>& adj){
    vis[u] = true;
    for(auto &v : adj[u]){
        if(v == parent) continue; // Skip the parent node
        if(vis[v]) return true; // If we encounter a visited node, there's a cycle
        if(dfs(v, u, vis, adj)) return true; // Recur for the next node
    }
    return false;
}
bool isCycle(int V, vector<vector<int>>& edges) {
    vector<bool>vis(V, false);
    vector<vector<int>> adj(V);
    for(auto &edge : edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]); 
    } 
    for (int i = 0; i < V; i++)
    {
        if(!vis[i] && dfs(i,-1,vis,adj)){
            return true;
        }
        return false;
    }
    
}
int main()
{
    int V = 5; // Nodes 0 to 4
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 4}, {2, 3},{3,4}};
    cout<<isCycle(V,edges)<<endl;
    return 0;
}