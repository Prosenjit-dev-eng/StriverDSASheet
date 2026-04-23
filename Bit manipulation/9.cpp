#include<bits/stdc++.h>
using namespace std;
int singleNO(vector<int>nums){
    int n = nums.size();
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        j = j^nums[i];
    }
    return j;
}
int main()
{
    vector<int>nums={4,1,2,1,2};
    cout<<singleNO(nums)<<endl;
    return 0;
}