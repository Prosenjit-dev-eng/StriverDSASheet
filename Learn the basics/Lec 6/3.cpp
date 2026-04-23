#include<iostream>
#include<vector>
#include<algorithm>
//You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.
//Return the maximum possible frequency of an element after performing at most k operations.
using namespace std;
int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long int maxfreq = 0, l = 0, r = 0, n = nums.size(), total= 0;

        for ( r = 0; r < n; r++)
        {
            total += nums[r];
            while(l+1 <= r && (nums[r]*(r-l+1LL) > (total+k)))// window length = (r-l+1)
            {
                total -= nums[l];
                l++;
            }
            maxfreq = max(maxfreq, (r-l+1));
        }
        return maxfreq;
        
}
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);

    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    int k;
    cin>>k;
    cout<<maxFrequency(v,k)<<endl;
    return 0;
}