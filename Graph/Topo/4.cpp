#include<bits/stdc++.h>
using namespace std;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &it : prerequisites){
            adj[it[1]].push_back(it[0]);// coz we have to first choose the next program before 0th 
        }
        vector<int>indegree(numCourses,0);
        for(int i = 0; i < numCourses; i++){
            for(int it : adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        if(ans.size()!=numCourses) return {};
        return ans;
    }
int main()
{
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0}};
    vector<int> result = findOrder(numCourses, prerequisites);
    if(result.empty()) {
        cout << "[]" << endl;
    } else {
        cout << "[";
        for(size_t i = 0; i < result.size(); i++) {
            cout << result[i];
            if(i != result.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}