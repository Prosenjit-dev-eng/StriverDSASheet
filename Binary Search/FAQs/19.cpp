#include<bits/stdc++.h>
using namespace std;
int maximum(vector<int>&v, int n){
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
       ans = max(v[i],ans);
    }
   return ans;
}
int sum(vector<int>&v, int n){
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += v[i];
    }
  return ans;  
}
int students(vector<int>&v, int n, int mid){
    int stu = 1, pagesGivenStu = 0;
    for (int i = 0; i < n; i++)
    {
       if(pagesGivenStu+v[i]<=mid) pagesGivenStu+=v[i];
       else
       {
        stu++;
        pagesGivenStu = v[i];
       }
        
    }
    
    return stu;
}
int bookAllocation(vector<int>&v, int n, int m){
    if(m>n) return -1;
    int ans = 0;
    int low = maximum(v,n), high = sum(v,n);
    while (low<=high)
    {
        int mid = low + (high - low)/2;
        if(students(v,n,mid)>m){
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return ans;
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

    int m;
    cin>>m;

    cout<<bookAllocation(v,n,m)<<endl;
    return 0;
}