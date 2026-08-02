#include<bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int>vis(V,0);
    pq.push({0,0});
    int sum = 0;
    // E
    while (!pq.empty())
    {
        // logE
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second;
        if(vis[node]) continue;
        // We add the node in the mst ,so we use vis here
        vis[node] = 1;
        sum += wt;
        // eloge
        for(auto &ngbr : adj[node]){
            int adjNode = ngbr[0];
            int edgeWt = ngbr[1];
            if(!vis[adjNode]){
                pq.push({edgeWt,adjNode});
            }
        }
    }
    return sum;
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