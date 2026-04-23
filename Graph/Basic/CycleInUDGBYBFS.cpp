#include<bits/stdc++.h>
using namespace std;
bool bfs(int u, vector<bool>&vis, vector<vector<int>>& adj){
    queue<pair<int,int>>q;// Node,parent
    q.push({u,-1});
    vis[u] = true;
    while (!q.empty())
    {
        pair<int,int>p = q.front();
        q.pop();
        int src = p.first;
        int par = p.second;
        for(auto& v : adj[src]){
            if(!vis[v]){
                vis[v] = true;
                q.push({v,src});
            }
            else if(v != par){
                return true;
            }
        }
        
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
        if(!vis[i] && bfs(i,vis,adj)){
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