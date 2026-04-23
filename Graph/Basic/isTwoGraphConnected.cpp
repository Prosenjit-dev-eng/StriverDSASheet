#include <bits/stdc++.h>
using namespace std;

void dfs(int v, vector<int> &vis, vector<vector<int>> &adj) {
    vis[v] = 1;
    for (int u = 1; u < adj.size(); u++) {
        if (adj[v][u] == 1 && !vis[u]) {
            dfs(u, vis, adj);
        }
    }
}

vector<vector<int>> adjMatrix(int v, int e) {
    vector<vector<int>> adj(v + 1, vector<int>(v + 1, 0));
    for (int i = 0; i < e; i++) {
        int u, w;
        cin >> u >> w;
        adj[u][w] = 1;
        adj[w][u] = 1;
    }
    return adj;
}

bool isConnected(vector<vector<int>> &adj, int v) {
    vector<int> vis(v + 1, 0);
    dfs(1, vis, adj);
    for (int i = 1; i <= v; i++) {
        if (!vis[i]) return false;
    }
    return true;
}

int main() {
    int v, e;
    cin >> v >> e;

    vector<vector<int>> adj = adjMatrix(v, e);

    if (isConnected(adj, v))
        cout << "Graph is Connected\n";
    else
        cout << "Graph is NOT Connected\n";

    return 0;
}
