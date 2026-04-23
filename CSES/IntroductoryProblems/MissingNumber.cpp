#include<bits/stdc++.h>
using namespace std;
long long missingNumber(vector<long long>v){
    int n = v.size()+1;
    long long total = (long long)n*(n+1)/2;
    long long sum = accumulate(v.begin(), v.end(), 0LL);// Mind it
    return total - sum;
}
int main()
{
    int n;
    cin>>n;
    vector<long long>arr(n-1);
    for (int i = 0; i < n-1; i++)
    {
        cin>>arr[i];
    }
    cout<<missingNumber(arr)<<endl;
    return 0;
}