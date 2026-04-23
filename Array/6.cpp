#include<iostream>
#include<vector>
using namespace std;

vector<int>moveZeroesAtEnd(vector<int>& v, int n){
    int j = - 1;
    for (int i = 0; i < n; i++)
    {
        if(v[i] == 0){
            j = i;
            break;
        }
    }
    if(j == -1) return v;

    for (int i = j+1; i < n; i++)
    {
        if(v[i] != 0){ swap(v[i],v[j]);
        j++;
        }
    }
    return v;
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

    vector<int> ans = moveZeroesAtEnd(v,n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
    return 0;
}