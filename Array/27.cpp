#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int longestConsecutiveArray(vector<int> &v, int n){
    sort(v.begin(),v.end());
    int longest = 1, cntcurr = 0, last_smaller = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        if((v[i] - 1) == last_smaller){
            cntcurr++;
            last_smaller = v[i];
        }
        else if (v[i] != last_smaller)
        {
            cntcurr = 1;
            last_smaller = v[i];
        }
         longest = max(longest,cntcurr);
    }
    return longest;
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

    cout<<longestConsecutiveArray(v,n)<<endl;
    return 0;
}