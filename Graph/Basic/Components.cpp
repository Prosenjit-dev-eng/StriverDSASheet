#include<bits/stdc++.h>
using namespace std;
int countComponents(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    for(auto &edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    queue<int> q;
    vector<int> vis(V, 0);
    int cnt = 0;
    for(int i = 0; i < V; i++) {
        if(!vis[i]) {
            cnt++;
            q.push(i);
            vis[i] = 1;
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                for(auto &it : adj[node]) {
                    if(!vis[it]) {
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
        }
    }
    return cnt;
}
int main()
{
    int V = 5; // Nodes 0 to 4
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 4}};
    int result = countComponents(V, edges);
    cout << "Number of Connected Components: " << result << endl;
    return 0;
}