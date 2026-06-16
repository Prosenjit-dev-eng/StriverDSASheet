#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;
        int n = intervals.size();
        int i = 0;
        //Left part
        while(i < n && intervals[i][1] < newInterval[0]/*Start*/){
            res.push_back(intervals[i]);
            i++;
        }
        // Middle part
        while(i < n && intervals[i][0] <= newInterval[1]/*End*/){
            newInterval[0] = min(newInterval[0],intervals[i][0]);
            newInterval[1] = max(newInterval[1],intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        // Right part
        while(i < n){
            res.push_back(intervals[i]);
            i++;
        }
        return res;     
}
int main()
{
    vector<vector<int>> intervals = {{1,3},{6,9}};
    vector<int> newinterval = {2,5};
    vector<vector<int>> res = insert(intervals,newinterval);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
        
    }
     
    return 0;
}