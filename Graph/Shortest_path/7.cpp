#include<bits/stdc++.h>
using namespace std;
vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S){
    vector<int>dist(V,1e9);// Distance array
    dist[S] = 0;
    vector<pair<int,int>>adj[V];
    // Relaxation for n-1 times
    for(int i = 0; i < V-1; i++){
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e8 && dist[u]+wt < dist[v]) dist[v] = dist[u]+wt;
        }
    }
    // For negative cycle 
    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if(dist[u] != 1e8 && dist[u]+wt < dist[v]) return {};
    }

    return dist;
}
int main()
{
    int V = 6, S = 0;
    vector<vector<int>>edges = {{3,2,6},{5,3,1},{0,1,5},{1,5,-3},{1,2,-2},{3,4,-2},{2,4,3}};
    vector<int>ans = bellman_ford(V, edges, S);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}