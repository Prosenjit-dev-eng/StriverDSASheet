#include<bits/stdc++.h>
using namespace std;
void selectionSort(vector<int>&v, int n){
    for (int i = 0; i < n-1; i++)
    {
        int min_idx = i;
        for (int j = i+1; j < n; j++)
        {
            if(v[min_idx]>v[j]) min_idx = j;
        }
        if (min_idx!=i)
        {
            swap(v[i],v[min_idx]);
        }
        
    }
    
}
int main()
{
    vector<int>v = {68,75,25,33,48};
    selectionSort(v,5);
    for (int i = 0; i < 5; i++)
    {
        cout<<v[i]<<endl;
    }
    
    return 0;
}