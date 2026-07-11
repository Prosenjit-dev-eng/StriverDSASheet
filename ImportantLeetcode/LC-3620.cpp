#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long,int>P;
bool check(unordered_map<int,vector<vector<int>>>& adj, int mid, int n, long long k){
    priority_queue<P,vector<P>,greater<P>> pq;
    vector<ll>dist(n,1e9);
    dist[0] = 0; 
    pq.push({0,0});
    while (!pq.empty())
    {
        ll d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(d > k) return false;

        if(node == n - 1) return true;
        // Total cost reaching from src to node = d
        if(dist[node]<d) continue;
        for(auto& it : adj[node]){
            // auto it = vector<int>
            int adjNode = it[0]; 
            int cost = it[1];
            if(cost < mid) continue;

            if((d+cost) < dist[adjNode]){
                dist[adjNode] = (d + cost);
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    return false;

}
int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
    int n = online.size();
    // Adjacency List
    unordered_map<int,vector<vector<int>>> adj;
    int l = INT_MAX;
    int r = 0;
    for(auto& e : edges){
        int u = e[0];
        int v = e[1];
        int cost = e[2];

        if(!online[u] || !online[v]) continue;

        adj[u].push_back({v,cost});
        l = min(l,cost);
        r = max(r,cost);
    }

    int ans = -1;
    while (l <= r)
    {
        int mid = l + (r-l)/2;
        if (check(adj,mid,n,k))
        {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
        
    }
    return ans;
    
}

int main()
{
    return 0;
}