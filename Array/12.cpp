#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int count  = 0;
        for (int j = 0; j < n; j++)
        {
            if (v[i] == v[j])
            {
                count++;
            }
            
        }
        if(count == 1) cout<<v[i]<<" ";
        
    }
        
    return 0;
}