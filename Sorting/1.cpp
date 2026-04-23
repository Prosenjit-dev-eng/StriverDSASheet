#include<bits/stdc++.h>
using namespace std;
void bubbleSort(vector<int>&v, int n){
    for (int i = 0; i < n-1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n-i-1; j++)
        {
            if(v[j+1] < v[j]){
                flag = 1;
                swap(v[j],v[j+1]);
            }
        }
        if (!flag)
        {
            break;
        }
        
        
    }
    
}
int main()
{
    int n = 6;
    vector<int>array = {13,46,24,52,20,9};
    bubbleSort(array,n);
    for (int i = 0; i < 6; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}