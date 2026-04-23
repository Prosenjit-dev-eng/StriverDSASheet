#include<bits/stdc++.h>
using namespace std;
// Undirected unweighted graph
int main()
{
    int n, m;
    cin >> n >> m;// n = vertices, m = edges
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0)); // Adjacency matrix initialized to 0
    // & n+1 for 1-based indexing
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; 
    }
    cout << "Adjacency Matrix:" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}