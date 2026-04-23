// Count no. of occurences of a number
// Brute force
/*int count(int arr[], int n, int x){
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            counter++;
        }
        
    }
    return counter;
}*/
// By hashing
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    // Precompute
    int hash[13] = {0};// Initialize with zero
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] += 1;
    }
    
    int q;
    cin>>q;
    while (q--)
    {
        int num;
        cin>>num;

        // Fetch
        cout<<hash[num]<<endl;
    }
    
    return 0;
}