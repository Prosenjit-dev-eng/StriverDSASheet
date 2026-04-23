#include<iostream>
#include<vector>
using namespace std;
int findSingularElemenet(vector<int> &nums, int n){
    for (int i = 0; i < n; i++)
    {
        int a = nums[i];
        int count  = 0;
        for (int j = 0; j < n; j++)
        {
            if(a == nums[j]) count++;
        }
        if(count == 1) return nums[i];
    }
    return -1;
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

    cout<<findSingularElemenet(v,n)<<endl;
    return 0;
}