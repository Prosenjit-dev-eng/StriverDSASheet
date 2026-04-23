#include<bits/stdc++.h>
using namespace std;
int maxArea(vector<int>& height) {
    int n = height.size();
    int l = 0, r = n-1;
    int maxi = INT16_MIN;
    while(l < r)
    {
        int area = min(height[l],height[r])*(r-l);
        maxi = max(maxi,area);
        if(height[l] < height[r]) l++;
        else r--;
        
    }
    return maxi;
}
int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(height) << endl;
    return 0;
}