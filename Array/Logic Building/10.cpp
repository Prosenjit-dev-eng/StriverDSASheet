// Intersection by array 
#include<iostream>
#include<vector>
using namespace std;

vector<int> findIntersection(vector<int> a, vector<int> b){
    int n = a.size();
    int m = b.size();

    int i = 0, j = 0;
    vector<int> intersection;

    while (i<n && j<m)
    {
        if(a[i] == b[j]){
            if(intersection.size() == 0 || intersection.back() != a[i]){// like a = 1,1
                intersection.push_back(a[i]); 
            }
            i++;
            j++;
        }

        else if(a[i]<b[j]) i++;
            else{
            j++;
            }
    }

    return intersection;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b(m);
    for (int i = 0; i < a.size(); i++)
    {
        cin>>a[i];
    }
        for (int j = 0; j < b.size(); j++)
    {
        cin>>b[j];
    }
    vector<int> ans = findIntersection(a,b);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
    return 0;
}