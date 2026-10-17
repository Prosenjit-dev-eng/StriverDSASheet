#include<bits/stdc++.h>
using namespace std;
int secondHighestOcuuringElement(vector<int>nums){
    map<int,int>freq;
    for(int i : nums) freq[i]++;
    int maxiCount = 0, maxele = 0;
    int ans = -1,  smaxiCount = -1;
    for(auto m : freq){
        int ele = m.first, cnt = m.second;
        if(cnt > maxiCount){
            ans = maxele;
            smaxiCount = maxiCount;
            
            maxele = ele;
            maxiCount = cnt;

        }
        else if(cnt > smaxiCount && cnt < maxiCount){
            ans = ele;
            smaxiCount = cnt;
        }
    }
    return ans;
}
int main()
{
    vector<int>nums = {1,1,2,2,2,2,2,3,3,3};
    cout<<secondHighestOcuuringElement(nums)<<endl;

    return 0;
}