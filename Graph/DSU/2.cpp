#include<bits/stdc++.h>
using namespace std;
// Union by size and path compression
class DisjointSetUnion{
    vector<int> parent, size;
    public:
    DisjointSetUnion(int n)
    {
        parent.resize(n+1);
        size.resize(n+1, 1);// 1 based indexing
        for(int i=0;i<=n;i++)
            parent[i] = i;
    }
    int findUltimateParent(int node)
    {
        if(node == parent[node])
            return node;
        return parent[node] = findUltimateParent(parent[node]);// By storing the ultimate parent in the parent array, we are doing path compression
    }
    void unionBySize(int u, int v)
    {
        int ultimateParentU = findUltimateParent(u);
        int ultimateParentV = findUltimateParent(v);
        if(ultimateParentU == ultimateParentV)// same component, no need to do union
            return;
        if(size[ultimateParentU] < size[ultimateParentV])
        {
            parent[ultimateParentU] = ultimateParentV;// smaller parent
            size[ultimateParentV] += size[ultimateParentU];
        }
        else
        {
            parent[ultimateParentV] = ultimateParentU;
            size[ultimateParentU] += size[ultimateParentV];
        }
    }
};
int main()
{
    DisjointSetUnion ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // Same or not
    if(ds.findUltimateParent(3) == ds.findUltimateParent(7))
        cout<<"Same\n";
    else
        cout<<"Not Same\n";
    ds.unionBySize(3, 7);
    return 0;
    return 0;
}