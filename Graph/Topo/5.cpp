#include<bits/stdc++.h>
using namespace std;
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> revAdj(n);
    for (int i = 0; i < n; i++)
    {
        for(auto &it : graph[i]){
            revAdj[it].push_back(i);
        }
    }
    
        vector<int>indegree(n,0);
        for(int i = 0; i < n; i++){
            for(int it : revAdj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<int>ans;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int it : revAdj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans; 
}
int main()
{
    vector<vector<int>> graph = {
        {1,2},{2,3},{5},{0},{5},{},{}
    };
    vector<int>ans = eventualSafeNodes(graph);
    for(auto &it : ans) cout<<it<<" ";
    return 0;
}