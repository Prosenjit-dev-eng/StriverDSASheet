#include<bits/stdc++.h>
using namespace std;
class DisjointSetUnion
{
    vector<int> parent, rank;
    public:
    DisjointSetUnion(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1, 0);// 1 based indexing
        for(int i=0;i<=n;i++)
            parent[i] = i;
    }
    int findUltimateParent(int node)
    {
        if(node == parent[node])
            return node;
        return parent[node] = findUltimateParent(parent[node]);// By storing the ultimate parent in the parent array, we are doing path compression
    }
    void unionByRank(int u, int v)
    {
        int ultimateParentU = findUltimateParent(u);
        int ultimateParentV = findUltimateParent(v);
        if(ultimateParentU == ultimateParentV)// same component, no need to do union
            return;
        if(rank[ultimateParentU] < rank[ultimateParentV])
            parent[ultimateParentU] = ultimateParentV;// smaller parent
        else if(rank[ultimateParentV] < rank[ultimateParentU])
            parent[ultimateParentV] = ultimateParentU;
        else // same
        {
            parent[ultimateParentV] = ultimateParentU;
            rank[ultimateParentU]++;
        }
    }
}; 
// Kruskal algorithm

int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<pair<int,pair<int,int>>> edges;
    // o(V+E) where V is the number of vertices and E is the number of edges
    for (int i = 0; i < V; i++)
    {
       for(auto it: adj[i]){
        int adjNode = it[0];
        int wt = it[1];
        int node = i;

        edges.push_back({wt,{node,adjNode}});

       } 
    }
    DisjointSetUnion dsu(V);
    // Sort=> o(ElogE) where E is the number of edges
    sort(edges.begin(),edges.end());
    int mstWt = 0;
    // O(V*4*alpha) where m is the number of edges and alpha is the inverse Ackermann function
    for(auto it : edges){
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if(dsu.findUltimateParent(u) != dsu.findUltimateParent(v)){
            mstWt += wt;
            dsu.unionByRank(u,v);
        }
    }
    return mstWt;
        
}
int main()
{
    int V = 5;
    vector<vector<int>> adj[V];
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});
    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});
    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});
    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    cout << spanningTree(V, adj) << endl;
    return 0;
}