#include<bits/stdc++.h>
using namespace std;
int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
    unordered_set<int>st(forbidden.begin(),forbidden.end());
    // a <= 2000
    // b <= 2000
    // x <= 2000
    // forbidden[i] <= 2000
    vector<vector<int>>vis(6001,vector<int>(2,-1));// 0 = forward, 1 = backward
    queue<pair<int,int>>q;// pos or b or f
    q.push({0,0});
    int steps = 0;
    while (!q.empty())
    {
        int sz = q.size();
        while(sz--){
        int pos = q.front().first;
        int dir = q.front().second;
        q.pop();
        if(pos == x) return steps;
        // 1st I have to do forward jump
        int forward = pos + a;
        if(forward <= 6000 && (st.find(forward) == st.end()) && vis[forward][0] == -1){
            vis[forward][0] = 1;
            q.push({forward,0});
        }
        int backward = pos - b;
        // dir == 0 then i can do backward jump, coz no 2 backward jumps
        if(dir == 0 && backward >= 0 && (st.find(backward) == st.end()) && vis[backward][1] == -1){
            vis[backward][1] = 1;
            q.push({backward,1});
        }
    }
        steps++;
    }
    return -1;
    
}
int main()
{
    vector<int>forbidden = {14,4,18,1,15};
    int a = 3, b = 15, x = 9;
    cout<<minimumJumps(forbidden,a,b,x)<<endl;
    return 0;
}