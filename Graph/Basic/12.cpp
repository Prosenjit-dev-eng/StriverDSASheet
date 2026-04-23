#include<bits/stdc++.h>
using namespace std;
bool check(int s, int  V, vector<vector<int>>& graph, vector<int>& color){
    queue<int>q;
    q.push(s);
    color[s] = 0;
    while (!q.empty())
    {
        int node  = q.front();
        q.pop();
        for(auto& it : graph[node]){
            //if the adjacent node is not colored then color it with opposite color
            if(color[it] == -1){
                color[it] = !color[node];
                q.push(it);
            }
            // if the adjacent node is colored and has the same color as the current node then the graph is not bipartite
            else if(color[it] == color[node]){
                return false;
            }
        }
    }
    return true;
    
}
bool isBipartite(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> color(V, -1);
    for(int i = 0; i < V; i++){
        if(color[i] == -1){
            if(!check(i, V, graph, color)){
                return false;
            }
        }
    }
    return true;
    
}
int main()
{
    vector<vector<int>> graph = {{1,3},{0,2},{1,3},{0,2}};
    if(isBipartite(graph)){
        cout << "The graph is bipartite." << endl;
    } else {
        cout << "The graph is not bipartite." << endl;
    }
    return 0;
}