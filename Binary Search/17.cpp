#include<bits/stdc++.h>
using namespace std;
/* Brute force*/
/*for (int i = 0; i < n; i++)
{
   if (arr[i]<k)
   {
    k++;

   }
   else{
    break;
   }
}return i;*/

int missingK(vector<int>&v,int n, int k){
    int low = 0, high = n - 1;
    while (low<=high)
    {
        int mid = low + (high - low)/2;
        int missing = v[mid] - (mid+1);
        if(missing < k) low  = mid + 1;
        else high = mid - 1;
    }
      return low + k;
}
int main()
{
        int n;
    cin>>n;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    int k;
    cin>>k;

    cout<<missingK(v,n,k)<<endl;
    return 0;
}