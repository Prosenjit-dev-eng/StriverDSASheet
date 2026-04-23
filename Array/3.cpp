#include<iostream>
#include<vector>
using namespace std;
bool isSorted(vector<int> &arr, int n){
    for (int i = 0; i < n; i++)
    {
        if(arr[i+1] < arr[i]){
            return false;
        }
    }
    return true;
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
    cout<<isSorted(arr,n)<<endl;
    return 0;
}