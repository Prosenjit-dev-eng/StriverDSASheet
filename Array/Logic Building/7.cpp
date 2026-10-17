#include<iostream>
#include<vector>
#include<set>
using namespace std;
// Easy union with set
vector<int> Findunion(int arr1[], int arr2[], int n, int m){
    set<int> s;
    vector<int> Union;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr1[i]);
    }
    for (int j = 0; j < m; j++)
    {
        s.insert(arr2[j]);
    }

    for(auto &itr : s) Union.push_back(itr);
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