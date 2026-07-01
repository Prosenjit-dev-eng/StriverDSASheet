#include<bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
        vector<int>res;
        deque<int>dq;
        for(int i = 0; i < n; i++){
            if(!dq.empty() && dq.front() <= i - k){
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] <= nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if(i >= k - 1) res.push_back(nums[dq.front()]);// coz the window starts from  k - 1 index

        }
        return res;
}
int main()
{
    vector<int>nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int>res = maxSlidingWindow(nums,k);
    for(auto r : res){
        cout<<r<<endl;
    }
    return 0;
}