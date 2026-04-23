#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int sum = 0;
        int minL = INT_MAX;
        while(j < n){
            sum += nums[j];
            while(sum >= target){
                minL = min(minL, j - i + 1);
                sum -= nums[i];
                i++;
            }
            j++;

        }
        return (minL == INT_MAX) ? 0 : minL;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    int result = sol.minSubArrayLen(target, nums);
    cout << "Minimum length of subarray: " << result << endl;
    return 0;
}