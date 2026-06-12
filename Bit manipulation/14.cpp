#include<bits/stdc++.h>
using namespace std;

    vector<int> singleNumber(vector<int>& nums) {
        vector<int>res;
        long long xorr = 0;
        for(int i : nums) xorr ^= i;
        long long rightmost = (xorr^(xorr-1)) & xorr;// if xorr = -2^31 & (-2^31) an integer can't store it
        int b1 = 0, b2 = 0;
        for(int i : nums){
            if(i & rightmost) b1^=i;
            else b2^=i;
        }
        res.push_back(b1);
        res.push_back(b2);
        return res;
    }

int main()
{
    vector<int>nums = {1,2,1,3,2,5};
    vector<int>res = singleNumber(nums);
    for(int i : res) cout<<i<<" ";
    
    return 0;
}