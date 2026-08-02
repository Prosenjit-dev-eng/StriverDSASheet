#include<bits/stdc++.h>
using namespace std;
int m,n;
vector<vector<int>>dir = {{-1,0},{1,0},{0,-1},{0,1}};
void dfs(vector<vector<int>>& isInfected,int i, int j, vector<vector<int>>&vis, int& wall,vector<pair<int,int>>&region,set<pair<int,int>>&frontier){
    vis[i][j] = 1;
    region.push_back({i,j});
    for(auto &d : dir){
        int nr = i + d[0];
        int nc = j + d[1];
        if(nr < 0 || nr >= m || nc >= n || nc < 0) continue;
        if (isInfected[nr][nc] && !vis[nr][nc])
        {
            dfs(isInfected,nr,nc,vis,wall,region,frontier);
        }
        else if(isInfected[nr][nc] == 0){
            wall++;
            frontier.insert({nr,nc});

        }
        
    }

}
int containVirus(vector<vector<int>>& isInfected) {
    m = isInfected.size(), n = isInfected[0].size();

    int ans = 0;
    while (true)
    {
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<set<pair<int,int>>>frontiers;
        vector<vector<pair<int,int>>>regions;
        vector<int>walls;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isInfected[i][j] == 1 && !vis[i][j])
                {
                    int wall = 0;
                    vector<pair<int,int>>region;
                    set<pair<int,int>> frontier;
                    dfs(isInfected,i,j,vis,wall,region,frontier);

                    regions.push_back(region);
                    frontiers.push_back(frontier);
                    walls.push_back(wall);
                }
                
            }
            
        }
        if(regions.empty()) break;
        int mx = 0, idx = -1;
        for (int i = 0; i < regions.size(); i++)
        {
            if(mx < frontiers[i].size()){
                mx = frontiers[i].size();
                idx = i;
            }
        }
        if(mx == 0) break;
        ans += walls[idx];

        // Quarantine chosen region
        for(auto &cell : regions[idx])
        {
            isInfected[cell.first][cell.second] = -1;
        }
        // Spread every other region
        for(int i=0;i<regions.size();i++)
        {
            if(i == idx) continue;

            // THIS IS WHERE B SPREADS
            for(auto &cell : frontiers[i])
            {
                isInfected[cell.first][cell.second] = 1;
            }
        }

    }
    return ans;
    
}
int main()
{
    vector<vector<int>> isInfected = {{0,1,0,0,0,0,0,1},
                                   {0,1,0,0,0,0,0,1},
                                   {0,0,0,0,0,0,0,1},
                                   {0,0,0,0,0,0,0,0}};
    cout << containVirus(isInfected) << endl;
    return 0;
}