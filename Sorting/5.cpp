#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>&v, int low, int high){
    int pivot = v[low];
    int start = low;
    int end = high;
    while (start <= end)
    {
        // While we get smaller element <= pivot , increment start
        while (v[start] <= pivot) start++;
        // While we get smaller element > pivot , decrement end

        while (v[end] > pivot) end--;
        if(start < end) swap(v[start],v[end]);
        
    }
    swap(v[low],v[end]);
    return end;
    
}
void quickSort(vector<int>&v, int low, int high){
    if(low < high){
        int pi = partition(v,low,high);
        quickSort(v,low,pi - 1);
        quickSort(v,pi+1,high);
    }
}
int main()
{
    vector<int>v = {7,6,10,5,9,2,1,15,7,10};
    quickSort(v,0,v.size()-1);
    for(auto &i : v) cout<<i<<endl;
    return 0;
}