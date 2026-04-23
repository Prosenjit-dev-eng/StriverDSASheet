#include<bits/stdc++.h>
using namespace std;
// Maximum points you can obtain from cards
int main()
{
    int k;
    cin>>k;
    int n;
    cin>>n;
    vector<int> v(n);
    int l = 0, r = k - 1;
    for(int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    int max_sum = 0;
    while(r<n){
        int sum = 0;
        for(int i = l; i <= r; i++)
        {
            sum += v[i];
        }
        max_sum = max(max_sum, sum);
        l++;
        r++;
    }
    cout<<max_sum<<endl;
    return 0;
}