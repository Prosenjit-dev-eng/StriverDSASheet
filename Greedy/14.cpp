#include<bits/stdc++.h>
using namespace std;
int sjf(vector<int>&arr){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    int sum = 0;
    int w = 0;
    for(int i = 0; i < n; i++){
        w += sum;
        sum += arr[i];
    }
    return w/n;
}
int main()
{
    vector<int>jobs = {4,3,7,1,2};
    cout<<sjf(jobs)<<endl;
    return 0;
}