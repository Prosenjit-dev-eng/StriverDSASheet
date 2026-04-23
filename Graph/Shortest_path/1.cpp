#include<bits/stdc++.h>
using namespace std;
vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
   vector<vector<int>>adj(N);
    for(auto &it : edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);

    }

    vector<int>dist(N,1e9);
    dist[src] = 0;
    queue<int>q;
    q.push(src);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it : adj[node]){
            if (dist[node] + 1 < dist[it])
            {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
            
        }
    }
    vector<int>res(N,-1);
    for (int i = 0; i < N; i++)
    {
        res[i] = dist[i];
    }
    return res;
    
    
}
int main()
{
    int n = 9, m = 10; 
    vector<vector<int>>edges = {{0,1},{0,3},{3,4},{4,5},{5, 6},{1,2},{2,6},{6,7},{7,8},{6,8}};
    int src = 0;
    vector<int>ans = shortestPath(edges,n,m,src);
    for(auto it : ans){
        cout<<it<<" ";
    }
    return 0;
}