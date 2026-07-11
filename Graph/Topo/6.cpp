#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        vector<int> indegree(V, 0);

        for (int i = 0; i < V; i++) {
            for (int it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for (int it : adj[node]) {
                indegree[it]--;

                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        return topo;
    }

    string findOrder(vector<string> &words) {

        vector<vector<int>> adj(26);
        vector<bool> present(26, false);

        // Mark all characters that appear
        for (auto &word : words) {
            for (char ch : word) {
                present[ch - 'a'] = true;
            }
        }

        // Build graph
        for (int i = 0; i < words.size() - 1; i++) {

            string s1 = words[i];
            string s2 = words[i + 1];

            int len = min(s1.length(), s2.length());

            for (int j = 0; j < len; j++) {

                if (s1[j] != s2[j]) {

                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;   // Only first different character matters
                }
            }
        }

        vector<int> topo = topoSort(26, adj);

        string ans;

        for (int x : topo) {
            if (present[x])
                ans += char(x + 'a');
        }

        return ans;
    }
};
int main()
{
    return 0;
}