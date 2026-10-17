#include<bits/stdc++.h>
using namespace std;
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());// To get the  maximum element at last
        // Suppose all element are 4, in 1,2,4, therefore the total sum should be 12 = 4*3 = 4*length
        int maxi = 1, i = 0;
        long long sum = 0;
        for(int j = 0; j < n; j++){
            int x = nums[j];
            sum += x;
            while((1LL)*x * (j - i + 1) - sum > k){ 
                sum -= nums[i];
                i++;
            }
            maxi = max(maxi, j - i + 1);

        }
        return maxi;
        
    }
int main()
{
    vector<int>nums = {1,2,4};
    cout<<maxFrequency(nums,5)<<endl;
    return 0;
}