#include<bits/stdc++.h>
using namespace std;
// union by rank and path compression
class DisjointSetUnion
{
    vector<int> parent, rank;
    public:
    DisjointSetUnion(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1, 0);// 1 based indexing
        for(int i=0;i<=n;i++)
            parent[i] = i;
    }
    int findUltimateParent(int node)
    {
        if(node == parent[node])
            return node;
        return parent[node] = findUltimateParent(parent[node]);// By storing the ultimate parent in the parent array, we are doing path compression
    }
    void unionByRank(int u, int v)
    {
        int ultimateParentU = findUltimateParent(u);
        int ultimateParentV = findUltimateParent(v);
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
int main()
{
    DisjointSetUnion ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    // Same or not
    if(ds.findUltimateParent(3) == ds.findUltimateParent(7))
        cout<<"Same\n";
    else
        cout<<"Not Same\n";
    ds.unionByRank(3, 7);
    return 0;
}