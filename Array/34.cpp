#include<bits/stdc++.h>
using namespace std;
int subarrSum(vector<int> &v, int n, int x){
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += v[k];
            }
            if(sum == x) cnt++;
            
        }
        
    }
    return cnt;
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
    cout<<subarrSum(v,n,x)<<endl;
    return 0;
}