#include<bits/stdc++.h>
using namespace std;
vector<long long>weird(long long n){
    vector<long long>ans;
    ans.push_back(n);
    while (n!=1)
    {
        if(n%2 != 0){
            n = (n*3+1);
            ans.push_back(n);
        }
        else
        {
            n/=2;
            ans.push_back(n);

        }
        
    }
    return ans;
    
}
int main()
{
    long long n;
    cin>>n;
    vector<long long> w = weird(n);
    for (auto x : w) cout<<x<<" ";
    cout<<endl;
    return 0;
}