#include<iostream>
#include<vector>
using namespace std;

vector<int>leaders(vector<int>&v, int n){
    vector<int>ans;
    int maxright = v[n-1];
    ans.push_back(v[n-1]);
    for (int i = n - 2; i >= 0; i--)
    {
        if(v[i] > maxright){ 
            ans.push_back(v[i]);
            maxright = v[i];
        }
    }
    return ans;
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
    vector<int>ans = leaders(v,n);
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}