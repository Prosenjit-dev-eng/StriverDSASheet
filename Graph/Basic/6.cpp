#include<bits/stdc++.h>
using namespace std;
int spanningTree(int v, vector<vector<int>> adj[])
{
    // Priority queue to store (weight, vertex) pairs
    // Wt, Node, Parent
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    vector<bool>isMst(v,0);
    vector<int>parent(v,-1);// Temporary parent array

    int cost = 0;
    pq.push({0,{0,-1}}); // Starting from node 0 with weight 0 and no parent
    while (!pq.empty())
    {
        int wt = pq.top().first;
        int node = pq.top().second.first;
        int par = pq.top().second.second;
        pq.pop();

        if(!isMst[node]){
            isMst[node] = 1;
            cost += wt;
            parent[node] = par; // Update parent

            for(auto it : adj[node]){
                int adjNode = it[0];
                int edgeWt = it[1];
                if(!isMst[adjNode]){
                    pq.push({edgeWt,{adjNode,node}});// Here the node is parent
                }
            }
        }
    }
    return cost;
}
int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<int>> adj[v];
    for(int i=0;i<e;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    cout<<spanningTree(v,adj)<<endl;
    return 0;
}