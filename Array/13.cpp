#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums, int n){
    int cnt  = 0, maxi = 0;
    for (int i = 0; i < n; i++)
    {
        if(nums[i] != 0){
            cnt++;
            maxi = max(maxi,cnt);
        }
        else{
        cnt = 0;
        }
    }
    return maxi;
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    cout<<findMaxConsecutiveOnes(v,n)<<endl;
    return 0;
}