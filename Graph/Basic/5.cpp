#include<bits/stdc++.h>
using namespace std;
// Adjlist representation of undirected unweighted graph
vector<vector<int>> adjList(int n,int m){

    vector<vector<int>> adj(n+1); // Adjacency matrix initialized to 0
    // & n+1 for 1-based indexing
    // vector<int> adj[n + 1];        // Array of vectors (C-style)
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    return adj;
}

int main()
{
    // int n, m;
    // cin >> n >> m;// n = vertices, m = edges
    // // vector<vector<int>> adj = adjList(n, m);
    // // cout << "Adjacency List:" << endl;
    // // for (int i = 1; i <= n; i++)
    // // {
    // //     cout<< i << ": ";
    // //     for (int j : adj[i])
    // //     {
    // //         cout << j << " ";
    // //     }
    // //     cout<<endl;
    // // }
    return 0;
}