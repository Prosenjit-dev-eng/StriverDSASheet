#include<bits/stdc++.h>
using namespace std;
// brute force
long double minimiseMaxDistance(vector<int>&v, int n, int k){
    vector<int>howmany(n-1,0);
    for(int gasStation = 1; gasStation <= k; gasStation++){
    long double maxSection = -1;
    int maxIdx = -1;
    for ( int i = 0; i < n-1; i++)// max division
        {
        long double diff = (v[i+1] - v[i]);// sorted array
        long double sectionLenj = diff/(long double)(howmany[i]+1);
        if(sectionLenj>maxSection){
            maxSection = sectionLenj;
            maxIdx = i;
            }
        }
    howmany[maxIdx]++;
    }
    long double maxAns = -1;
    for (int i = 0; i < n-1; i++)
    {
        long double diff = (v[i+1] - v[i]);
        long double sectionLenj = diff/(long double)(howmany[i]+1);
        maxAns = max(maxAns,sectionLenj);
    }
    return maxAns;
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

    int k;
    cin>>k;

    cout<<minimiseMaxDistance(v,n,k)<<endl;
    return 0;
}