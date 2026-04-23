#include<iostream>
#include<vector>
using namespace std;
// Brute force
int longestArraySum(vector<int>& arr, int n, int x){
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;

            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
                if(sum == x) len = max(len,j-i+1); 
            
        }
        
    }
    return len;
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
    cout<<longestArraySum(v,n,x)<<endl;
    return 0;
}