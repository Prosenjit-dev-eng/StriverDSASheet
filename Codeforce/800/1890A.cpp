#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int>v(n);
        for (int i = 0; i < n; i++)
        {
            cin>>v[i];
        }
        map<int,int>freq;// value -> count
        for(auto &i : v) freq[i]++;
        if(freq.size()>= 3 ) cout<<"NO"<<endl;
        else
        {
            int freq1 = freq.begin() -> second;
            int freq2 = freq.rbegin()->second;
            if (freq1 == freq2)
            {
                cout<<"YES"<<endl;
            }
            else if (n%2 == 1 && abs(freq1 - freq2) <= 1)
                {
                    cout<<"YES"<<endl;
                }
            else cout<<"NO"<<endl;
            
        }
        

    }
    return 0;
}