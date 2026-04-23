#include<bits/stdc++.h>
using namespace std;
void insertionSort(vector<int>&v, int n){
    for (int i = 1; i < n; i++)
    {
        int j = i-1;
        int curr = v[i];
        while (j>=0 && curr<v[j])
        {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = curr;
    }
    
}
int main()
{
    vector<int>v = {68,75,25,33,48};
    insertionSort(v,5);
    for (int i = 0; i < 5; i++)
    {
        cout<<v[i]<<endl;
    }
    
    return 0;
}
