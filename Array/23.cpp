#include<iostream>
#include<map>
#include<vector>
using namespace std;

int maxSubArrSum(vector<int>& arr, int n){
    // Brute force
    /*int maxi = INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i;k <= j; k++)
            {
                sum += arr[k];
            }
            maxi = max(sum,maxi);
        }
        
    }
    return maxi;*/   // =>time = o(n^3);

    // Optimal => Kadane's algorithm
    int sum = 0, maxi = INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(sum > maxi) maxi = sum;
        if(sum < 0) sum = 0;
    }
    return maxi;
}// time = o (n)
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    cout<<maxSubArrSum(v,n)<<endl;
    return 0;
}