#include<iostream>
#include<vector>
using namespace std;
vector<int>rearrangeArr(vector<int>&A,int n){
    vector<int>ans(n,0);
    int neg_idx = 1,pos_idx = 0;
    for (int i = 0; i < n; i++)
    {
        if(A[i] < 0){ ans[neg_idx] = A[i];
        neg_idx += 2;
        }
        else
        {
            ans[pos_idx] = A[i];
            pos_idx += 2;
        }
        

    }
    return ans;
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

    vector<int>res = rearrangeArr(v,n);
    for (int i = 0; i < n; i++)
    {
        cout<<res[i]<<endl;
    }
    
    return 0;
}