#include<iostream>
#include<vector>
#include<map>
using namespace std;
// Best
int longestSubArr(vector<int>& a, int n, int k){
    map<int,int>m;
    int sum = 0, length = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if(sum == k) length = max(length,i+1);
        if(m.find(sum)==m.end()) m[sum] = i;// m = index are = {10,15,17,24,25,-10} &
        // "If this prefix sum (sum) has not been seen before, store its index (i) in the map m."
        if(m.find(sum - k)!=m.end()) length = max(length,i-m[sum - k]);
//"If there is a previous prefix sum such that the difference between the current sum and that previous sum is k,
// then a subarray with sum k exists. Calculate its length and update the maximum length if it's longer."
    }
    return length;
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
    int x;
    cin>>x;
    cout<<longestSubArr(v,n,x)<<endl;
    return 0;
}