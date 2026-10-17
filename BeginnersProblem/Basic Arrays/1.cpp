#include<bits/stdc++.h>
using namespace std;
int cntOdds(vector<int>nums){
    int cnt = 0;
    for(auto &i : nums){
        if(i & 1) cnt++;
    }
    return cnt;
}
int main()
{
    vector<int>nums = {1,2,3,4,5};
    cout<<cntOdds(nums)<<endl;
    return 0;
}