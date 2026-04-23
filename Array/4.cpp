#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int uniquearray(vector<int>& arr, int n){
    int i = 0;
    
    for (int j = i+1; j < n; j++)
    {
        if(arr[i]!=arr[j]){
            i++;
            arr[i] = arr[j];
        }
    }
    for (int  k = 0; k <= i; k++)
    {
        cout<<arr[k]<<" ";
    }
    cout<<endl;
    return i+1;
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    int count = uniquearray(arr,n);
    cout<<"Count of unique elements:"<<count<<endl;
    return 0;
}