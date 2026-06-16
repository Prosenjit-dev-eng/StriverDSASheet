#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; // Number of test cases
    cin >> t;
    while (t--)
    {
        int n; // Length of array a
        cin >> n;
        vector<int> a(n); // Array a of length n
        for (int i = 0; i < n; i++) // Read elements of array a
            cin >> a[i];
        int cntOdd = 0;
        for (int i = 0; i < n; i++){ // Read elements of array a
            if (a[i] % 2 != 0)
            {
                cntOdd++;
            }
            
        }
        if(cntOdd%2 == 0) cout <<"YES"<<endl;
        else cout<<"NO"<<endl;            
    }
    return 0;
}