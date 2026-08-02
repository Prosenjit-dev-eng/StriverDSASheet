#include<bits/stdc++.h>
using namespace std;
// Kosaraju's Algorithm to find the number of strongly connected components in a directed graph
void dfs(int node, vector<int>adj[], vector<int>&vis, stack<int>&st){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,st);
        }
    }
    st.push(node);
}
void revDfs(int node, vector<int>adjT[], vector<int>&vis){
    vis[node] = 1;
    for(auto it: adjT[node]){
        if(!vis[it]){
            revDfs(it,adjT,vis);
        }
    }
}
int kosaraju(int V, vector<int>adj[]){
    vector<int>vis(V,0);
    // Stack-> We want to store the nodes in the order of their finishing times
    stack<int>st;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i,adj,vis,st);
        }
    }
    vector<int>adjT[V];
    for(int i=0;i<V;i++){
        vis[i] = 0;
        for(auto it: adj[i]){
            adjT[it].push_back(i);
        }
    }
    int scc = 0;
    // Finishing time in stack
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis[node]){
            scc++;
            revDfs(node,adjT,vis);
        }
    }
    return scc;
}
int main()
{
    int V = 5;
    vector<int> adj[V];
    adj[0].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(3);
    adj[3].push_back(4);
    cout << kosaraju(V, adj) << endl;
    return 0;
}