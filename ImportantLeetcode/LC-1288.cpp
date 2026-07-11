#include<bits/stdc++.h>
using namespace std;
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        auto lambda = [](vector<int>&v1,vector<int>&v2){
            if(v1[0] == v2[0]) return v1[1] > v2[1];
            return v1[0] < v2[0];
        };
        sort(intervals.begin(),intervals.end(),lambda);
        int last = intervals[0][1];
        int cnt = 1;
        for(int i = 0; i < n; i++){
            if(last >= intervals[i][1]) continue;
            last = intervals[i][1];
            cnt++;
        }
        return cnt;

    }
int main()
{
    return 0;
}