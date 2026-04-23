#include<bits/stdc++.h>
using namespace std;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int startingColor = image[sr][sc];
        if(startingColor == color) return image;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc] = color;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == startingColor){
                    image[nrow][ncol] = color;
                    q.push({nrow,ncol});
                }
            }
            
        }
        
        return image;
    }
int main()
{
    // image = [[1,1,1],[1,1,0],[1,0,1]];
    vector<vector<int>>image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, color = 2;
    vector<vector<int>>ans = floodFill(image, sr, sc, color);
    for(auto it : ans){
        for(auto jt : it){
            cout<<jt<<" ";
        }
        cout<<endl;
    }
    return 0;
}