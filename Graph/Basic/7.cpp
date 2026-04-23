#include<bits/stdc++.h>
using namespace std;

    void dfs(int v, vector<vector<int>>&adjL, vector<int>&vis){
        vis[v] = 1;
        for(auto it : adjL[v]){
            if(!vis[it]){
                dfs(it,adjL,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<vector<int>>adjL(v);
        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                if(isConnected[i][j] == 1 && i!=j){
                  adjL[i].push_back(j);
                }
            }
        }
        vector<int>vis(v,0);
        int cnt = 0;
        for(int i = 0; i < v; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, adjL, vis);
            }
        }
        return cnt;
    }

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>isConnected(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>isConnected[i][j];
        }
    }
    cout<<findCircleNum(isConnected)<<endl;
    return 0;
}