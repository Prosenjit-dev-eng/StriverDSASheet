#include<bits/stdc++.h>
using namespace std;
int len(vector<int>a){
    int n = a.size();
    int  l = 0,r = 0, maxlen = 0;
    map<int,int>mpp;
    while (r<n)
    {
        mpp[a[r]]++;
        // make it possible
        if(mpp.size()>2){
            mpp[a[l]]--;// map[a[l]] => frequency
            if(mpp[a[l]] == 0) mpp.erase(a[l]);
            l++;   
        } 
        
        if (mpp.size()<=2)
        {
            maxlen = (maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
    
}
int main()
{
    vector<int>arr = {1,2,3,2,2};
    cout<<len(arr)<<endl;
    return 0;
}