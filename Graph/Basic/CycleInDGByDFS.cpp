#include<bits/stdc++.h>
using namespace std;
bool dfs(int u, vector<bool>&vis, vector<vector<int>>& adj, vector<bool>&inrecursion){
    vis[u] = true;
    inrecursion[u] = true;

    for(auto &v : adj[u]){
        if(!vis[v] && (dfs(v,vis, adj,inrecursion))) return true; // If we encounter a visited node, there's a cycle
        else if(inrecursion[v] == true) return true; // Recur for the next node
    }
    inrecursion[u] = false;
    return false;
}
bool isCycle(int V, vector<vector<int>>& edges) {
    vector<bool>vis(V, false);
    vector<bool>inrecursion(V, false);

    vector<vector<int>> adj(V);
    for(auto &edge : edges){
        adj[edge[0]].push_back(edge[1]);
    } 
    for (int i = 0; i < V; i++)
    {
        if(!vis[i] && dfs(i,vis,adj,inrecursion)){
            return true;
        }
    }
    return false;
    
}
int main()
{
    int V = 3; // Nodes 0 to 4
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};
    cout<<isCycle(V,edges)<<endl;
    return 0;
}