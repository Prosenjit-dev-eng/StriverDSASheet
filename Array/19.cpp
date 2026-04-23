#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Brute force
/*string twoSum(int a[],int n,int x){
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(a[i] + a[j] == x) return "yes";
        }
        
    }
   return "no"; 
}*/
string twoSum(vector<int>&a,int n,int x){
    int i = 0, j = n - 1;
    sort(a.begin(),a.end());
    while (i<j)
    {
        int sum = a[i] + a[j];
        if(sum == x) return "Yes";
        else if(sum < x) i++;
        else j--;
    }
    return "No";
}
int main()
{
    vector<int> a = {2, 6, 5, 8, 9};
    int n  = a.size();
    int x = 14;

    cout<<twoSum(a,n,x)<<endl;
    return 0;
}