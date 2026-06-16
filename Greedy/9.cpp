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
        vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
        vector<vector<int>> res = merge(intervals);
        for(int i = 0; i < res.size(); i++){
            cout << res[i][0] << " " << res[i][1] << endl;
        }
    return 0;
}