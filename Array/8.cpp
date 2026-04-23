#include<iostream>
#include<vector>
#include<map>
using namespace std;
// Easy union with map
// As we are using only a single map the common element in arr1 and arr2 are treated as a single element for finding frequency, so there would be no duplicates.
vector<int> Findunion(int arr1[], int arr2[], int n, int m){
    map<int,int> freq;
    vector<int> Union;
    for (int i = 0; i < n; i++)
    {
        freq[arr1[i]]++;
    }
    for (int j = 0; j < m; j++)
    {
        freq[arr2[j]]++;  
    }

    for(auto &itr : freq) Union.push_back(itr.first);
    return Union;
}// time for set = o(log(m+n)) & (m+n) for the loops => total time = o((m+n)log(m+n))
int main()
{
    int arr1[] = {1,2,3,4,4};
    int arr2[] = {1,2,2,3,0,2};

    vector<int> v;
    v = Findunion(arr1,arr2,5,6);
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    
    return 0;
}