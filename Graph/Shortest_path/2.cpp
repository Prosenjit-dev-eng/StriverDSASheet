#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<vector<pair<int,int>>>& adj, vector<int>&vis, stack<int>&st){
    vis[node] = 1;
    for(auto &it : adj[node]){
        int v = it.first;
        if(!vis[v]){
            dfs(v,adj,vis,st);
        }
        
    }
    st.push(node);
}
vector < int > shortestPath(int N, int M, vector < vector < int >> & edges) {
    vector<vector<pair<int,int>>> adj(N);
    for(int i = 0; i < N; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v,wt});
    }
    // Topo sort
    vector<int>vis(N,0);
    stack<int>st;
    // T.c: O(N+E)
    for (int i = 0; i < N; i++)
    {
        if(!vis[i]) dfs(i,adj,vis,st);
    }

    // Distance array
    vector<int>dist(N,1e9);
    dist[0] = 0;
    
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        // tc = o(n+m)
        for(auto it : adj[node]){
            int v = it.first;
            int wt = it.second;

            if(dist[node]+wt < dist[v]){
                dist[v] = dist[node]+wt;
            }
        }

    }
    return dist;

}
int main()
{
    int N = 6, M = 7;
    vector<vector<int>>edges = {{0,1,2},{0,4,1},{1,2,3},{2,3,6},{4,2,2},{4,5,4},{5,3,1}};
    vector<int>ans = shortestPath(N,M,edges);
    for(auto it : ans){
        cout<<it<<" ";
    }
    return 0;
}