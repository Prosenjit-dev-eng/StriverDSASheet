#include<bits/stdc++.h>
using namespace std;
int cntPlatforms(vector<int>&arr, vector<int>&dep, int n){
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    int i = 0, j = 0,cnt = 0, maxCnt = 0;
    while (i < n)
    {
        if(arr[i] <= dep[j]){
            cnt++;
            i++;
        }
        else
        {
            cnt--;
            j++;
        }
        maxCnt = max(maxCnt,cnt);
    }
   return maxCnt; 
}
int main()
{
    vector<int>arr = {900, 945, 955, 1100, 1500, 1800};
    vector<int>dep = {920,1200,1130,1150,1900,2000};
    int n = 6;
    cout<<cntPlatforms(arr,dep,n)<<endl;
    return 0;
}