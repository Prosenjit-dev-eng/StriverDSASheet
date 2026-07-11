#include<bits/stdc++.h>
using namespace std;
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int,int>>>adj(n);
    // flights[i] = [fromi, toi, pricei] 
    for(auto &f : flights){
        int fromi = f[0];
        int toi = f[1];
        int pricei = f[2];
        adj[fromi].push_back({toi,pricei});
    }    
    queue<vector<int>>q;
    q.push({0,src,0});// stops,node,dist
    vector<int>dist(n,1e9);
    dist[src] = 0;
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int stops = it[0];
        int node = it[1];
        int d = it[2];
        if(stops > k) continue;
        for(auto &v : adj[node]){
            int adjNode = v.first;
            int costs = v.second;
            if(d+costs < dist[adjNode] && stops <= k){
                dist[adjNode] = d+costs;
                q.push({stops+1,adjNode,d+costs});
            } 
        }
    }
    return dist[dst] == 1e9 ? -1 : dist[dst];
}
int main()
{
    int n = 4, src = 0, dst = 3, k = 1;
    vector<vector<int>>flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    cout<<findCheapestPrice(n,flights,src,dst,k)<<endl; 
    return 0;
}