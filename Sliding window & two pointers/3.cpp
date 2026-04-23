#include<bits/stdc++.h>
using namespace std;
int len(vector<int>a,int k){
    int n = a.size();
    int  l = 0,r = 0, maxlen = 0,zeroes = 0;
    while (r<n)
    {
        if(a[r]==0) zeroes++;
        if(zeroes>k){
        if(a[l]==0) zeroes--;
            l++;
        }
        if (zeroes<=k)
        {
            maxlen = (maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
    
}
int main()
{
    vector<int>arr = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k = 3;
    cout<<len(arr,k)<<endl;
    return 0;
}