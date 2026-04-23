#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int S_maximum(vector<int> &arr, int n){
    int maxi = arr[0];
    int s_maxi = -1;
    for (int i = 1; i < n; i++)
    {
        if(arr[i]>maxi){
            s_maxi = maxi;// first it
            maxi = arr[i];
        }
        else if(arr[i] < maxi && arr[i] > s_maxi){
            s_maxi = arr[i];
        }
    }
    
    return s_maxi;
}
int S_smallest(vector<int> &arr, int n){
    int smallest = arr[0];
    int secondSmallest = INT16_MAX;
    for (int i = 1; i < n; i++)
    {
        if(arr[i]<smallest){
            secondSmallest = smallest;// first it
            smallest = arr[i];
        }
        else if(arr[i] != smallest && arr[i] < secondSmallest){
            secondSmallest = arr[i];
        }
    }
    
    return secondSmallest;
}// Time = o(n)

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    cout<<S_maximum(arr, n)<<endl;
    cout<<S_smallest(arr, n)<<endl;


    return 0;
}