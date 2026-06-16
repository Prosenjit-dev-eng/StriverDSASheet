#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int n = intervals.size();
        int cnt = 1;
        int lastEndTime = intervals[0][1];
        for(int i = 1; i < n; i++){
            if(intervals[i][0] >= lastEndTime){
                cnt++;
                lastEndTime = intervals[i][1];
            }
        }
        return n - cnt;
    }
};
int main()
{
    vector<vector<int>>intervals = {{1,2},{2,3},{3,4},{1,3}};
    Solution s;
    cout<<s.eraseOverlapIntervals(intervals)<<endl;
    return 0;
}