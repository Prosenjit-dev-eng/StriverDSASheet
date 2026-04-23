 #include<bits/stdc++.h>
 using namespace std;
 int maxSubarraySum(vector<int>& nums, int k) {
     int n = nums.size();
     int maxSum = INT_MIN;
     int j = k;
     while(j <= n){
         int i = 0, sum = 0;
         while(i < j){
             sum+=nums[i];
             i++;
            }
            maxSum = max(sum,maxSum);
            j++;
        }
        return maxSum;
}
int main()
    {
        vector<int> nums = {-1,-2,-3,-4,-5};
        int k = 4;
        cout<<maxSubarraySum(nums,k)<<endl;
        return 0;
    }
