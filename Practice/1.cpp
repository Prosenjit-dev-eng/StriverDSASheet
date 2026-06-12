#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
typedef long long ll;
    int getMaxDepth(unordered_map<int,vector<int>>& adj, int u, int par){
        int md = 0;
        for(auto ngbr : adj[u]){
            if(ngbr!=par){
                md = max(md,getMaxDepth(adj,ngbr,u)+1);
            }
        }
        return md;
    }
    ll findpow(int a, int b){
        ll ans = 1;
        while (b>0)
        {
            if(b&1){
                ans *= a;
            }
            a*=a;
            b>>=1;
        }
        return ans;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int maxDepth = getMaxDepth(adj,1,-1);
        return findpow(2,maxDepth - 1)%MOD;
    }
int main()
{
    return 0;
}