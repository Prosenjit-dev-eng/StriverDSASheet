#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<int>& bloomDay, int day, int m, int k){
        int cnt = 0, b = 0;// b == bouquets
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= day) cnt++;
            else{
                b += (cnt/k);
                cnt = 0;
            }
        }
        b += (cnt/k);
        return (b>=m) ? true : false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long)m*k > n) return -1;
        int l = *min_element(bloomDay.begin(),bloomDay.end()), r = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = 0;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(check(bloomDay,mid,m,k)){
                ans = mid;
                r = mid - 1;

            }
            else l = mid + 1;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> bloomDay = {1,10,3,10,2};
    int m = 3, k = 1;
    cout<<s.minDays(bloomDay,m,k)<<endl;
    return 0;
}
