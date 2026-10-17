#include<iostream>
#include<map>
#include<vector>
using namespace std;

int majorityElements(vector<int>& arr, int n){
    // Brute force
   /* map<int, int>m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    for(auto itr : m) {
        if(itr.second > n/2) return itr.first;
    }
    return -1;*/

    // Optimal =>  Moore’s Voting Algorithm,to keep maximum frequent element
    int cnt = 0, el;
    for (int i = 0; i < n; i++)
    {
        if(cnt == 0){
          cnt = 1;
          el = arr[i];
        }
        else if(arr[i] == el) cnt++;  
        else cnt--;

    }
    // By the above block we find the maximum element, which occurs in the array
    int cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == el) cnt1++;
    }
    if(cnt1>(n/2)) return cnt1;
    return -1;
}// time = o (n)
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    cout<<majorityElements(v,n)<<endl;
    return 0;
}