#include<bits/stdc++.h>
using namespace std;
class DSU{
    public:
    vector<int>rank,parent;
    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) parent[i] = i;
    }
    int findUp(int val){
        if(val == parent[val]) return val;
        return parent[val] = findUp(parent[val]);
    }
    void unionByRank(int u, int v)
    {
        int ultimateParentU = findUp(u);
        int ultimateParentV = findUp(v);
        if(ultimateParentU == ultimateParentV)// same component, no need to do union
            return;
        if(rank[ultimateParentU] < rank[ultimateParentV])
            parent[ultimateParentU] = ultimateParentV;// smaller parent
        else if(rank[ultimateParentV] < rank[ultimateParentU])
            parent[ultimateParentV] = ultimateParentU;
        else // same
        {
            parent[ultimateParentV] = ultimateParentU;
            rank[ultimateParentU]++;
        }
    }
};
int makeConnected(int n, vector<vector<int>>& connections) {
    DSU ds(n);
    int cntExtraEdges = 0;
    for(auto &con : connections){
        int u = con[0];
        int v = con[1];
        if(ds.findUp(u) == ds.findUp(v)) cntExtraEdges++;
        else ds.unionByRank(u,v);
        int connnectedComponents = 0;
        for (int i = 0; i < n; i++)
        {
            if(ds.parent[i] == i) connnectedComponents++;
        }
        int ans = connnectedComponents - 1;
        return cntExtraEdges >= ans ? ans : -1;
    }
}
int main()
{
    return 0;
}