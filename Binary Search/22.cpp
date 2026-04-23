#include<bits/stdc++.h>
using namespace std;
int maxidx(vector<vector<int>>&mat,int n, int m){
    int max_cnt = 0;
    int idx  = -1;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        // We can optimise it by binary search
        for (int j = 0; j < m; j++)
        {
            count += mat[i][j];
        }
        if(count > max_cnt){
            max_cnt = count;
            idx = i;
        }
        
    }
    return idx;
}
int main()
{
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>>v(n,vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>v[i][j];
        }
        
    }
    cout<<maxidx(v,n,m)<<endl;
    return 0;
}