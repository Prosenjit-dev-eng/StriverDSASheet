#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Dutch Flag algo
        int n = nums.size();
        int l = 0, h = n - 1 , mid = 0;
        while(mid <= h){
            if(nums[mid] == 0){
                swap(nums[l],nums[mid]);
                l++;
                mid++;
            }
            else if(nums[mid] == 1) mid++;
            else {
                swap(nums[h],nums[mid]);
                h--;
            }
        }
    }
};
int main()
{
    Solution s;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    s.sortColors(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    return 0;
}