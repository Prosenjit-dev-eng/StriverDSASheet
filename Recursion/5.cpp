#include<bits/stdc++.h>
using namespace std;
// Reverse an array
void reversearr(vector<int>&arr,int i){
    int n = arr.size();

    if(i>=n/2) return;
    swap(arr[i],arr[n-i-1]);
    reversearr(arr,i+1);
}
int main()
{
    vector<int>arr={1,2,3,4,2};
    reversearr(arr,0);
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}