#include<bits/stdc++.h>
using namespace std;
int findFloor(vector<int>&v,int n,int x){
    int low = 0, high = n-1;
    int ans = 0;
    while (low<=high)
    {
        int mid  = low + (high - low)/2;

        if(v[mid]<=x){
            ans = v[mid];
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return ans;
}
int findCeil(vector<int>&v,int n,int x){
    int low = 0, high = n-1;
    int ans = 0;
    while (low<=high)
    {
        int mid  = low + (high - low)/2;

        if(v[mid]>=x){
            ans  = v[mid];
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}
pair<int, int> getFloorAndCeil(vector<int>v, int n, int x) {
	int f = findFloor(v, n, x);
	int c = findCeil(v, n, x);
	return make_pair(f, c);
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
    int x;
    cin>>x;
    pair<int,int>ans = getFloorAndCeil(v,n,x);
    cout<<"Floor = "<<ans.first<<""<< "Ceil = "<<ans.second<<endl;
    return 0;
}