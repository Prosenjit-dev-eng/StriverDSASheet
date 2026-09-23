#include<bits/stdc++.h>
using namespace std;
// Bipartite
class Solution {
public:
    bool dfs(int src, vector<vector<int>>& graph, vector<int>&color){
        for(auto &it : graph[src]){
            if(color[it] == -1){
                color[it] = !color[src];
                if(!dfs(it,graph,color)) return false;
            }
            else if(color[it] == color[src]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                color[i] = 0;
                if(!dfs(i,graph,color)) return false;
            }
        }
        return true;
    }
};
int main()
{
    return 0;
}