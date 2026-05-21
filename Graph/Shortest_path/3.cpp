#include<bits/stdc++.h>
using namespace std;
// Djiskarta's Algo
// Using Pq
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vi dijkstra(int V, vvi adj[], int S) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int>dist(V,1e9);
    dist[S] = 0; 
    pq.push({0,S});
    while (!pq.empty())
    {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it : adj[node]){
            // auto it = vector<int>
            int edgewt = it[1];
            int adjNode = it[0]; 

            if((d + edgewt) < dist[adjNode]){
                dist[adjNode] = (d + edgewt);
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    return dist;

}
int main()
{
    int V = 5;
    vector<vector<int>> adj[V];
    adj[0].push_back({1,2});
    adj[0].push_back({2,4});
    adj[1].push_back({2,1});
    adj[1].push_back({3,7});
    adj[2].push_back({4,3});
    adj[3].push_back({5,1});
    adj[4].push_back({3,2});
    int S = 0;
    vector<int> result = dijkstra(V, adj, S);
    for(int i = 0; i < result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0;
}