#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node, vector<int>& color,vector<vector<int>>& graph, int col) {

    int n = graph.size();

    for (int k = 0; k < n; k++) {
        if (graph[node][k] && color[k] == col) {
            return false;
        }
    }

    return true;
}

bool solve(int node, vector<int>& color,vector<vector<int>>& graph, int m) {

    int n = graph.size();

    if (node == n) return true;

    for (int col = 1; col <= m; col++) {

        if (isSafe(node, color, graph, col)) {

            color[node] = col;

            if (solve(node + 1, color, graph, m))
                return true;

            color[node] = 0; // backtrack
        }
    }

    return false;
}

bool graphColoring(vector<vector<int>>& graph, int m) {

    int n = graph.size();

    vector<int> color(n, 0);

    return solve(0, color, graph, m);
}

int main() {

    int N = 4;
    int m = 3;

    vector<vector<int>> graph(N, vector<int>(N, 0));

    graph[0][1] = graph[1][0] = 1;
    graph[1][2] = graph[2][1] = 1;
    graph[2][3] = graph[3][2] = 1;
    graph[3][0] = graph[0][3] = 1;
    graph[0][2] = graph[2][0] = 1;

    cout << graphColoring(graph, m);

    return 0;
}