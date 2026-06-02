#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i = 1; i < n; i++){
            // After some merges, res.size() can be smaller than i, so res[i-1] may not exist. so use back()
            if(intervals[i][0] <= res.back()[1]) res.back()[1] = max(res.back()[1],intervals[i][1]);
            else res.push_back(intervals[i]); 
        }
        return res;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> intervals(n,vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin>>intervals[i][j];
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout<<intervals[i][j]<<" ";
        }
       cout<<endl; 
    }
    vector<vector<int>>v = merge(intervals);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    
     
    return 0;
}