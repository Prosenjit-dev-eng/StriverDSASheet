#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
void dfsUtil(int start, int vis[], vector<int> adj[], vector<int> &result) {
    vis[start] = 1;
    result.push_back(start);
    // Traversing all the adjacent nodes
    for (auto &&i : adj[start]) {

        if (!vis[i])  
        {
        cnt++;
        cout<<cnt<<endl;
        dfsUtil(i, vis, adj, result);
        }
    }
    
}
vector<int>dfsGraph(int V, vector<int> adj[]){
    int vis[V] = {0};
    int start = 0;
    vector<int>result;
    dfsUtil(start, vis, adj, result);
    return result;
}
int main()
{
    int V = 5; // Nodes 0 to 4
    vector<int> adj[V];

    // Sample edges (undirected)
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[2].push_back(4);
    adj[4].push_back(2);

    vector<int> result = dfsGraph(V, adj);

    cout << "DFS Traversal: ";
    for (int x : result) {
        cout << x << " ";
    }
    return 0;
}