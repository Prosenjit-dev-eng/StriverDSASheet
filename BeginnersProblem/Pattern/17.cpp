#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n-i; j++) cout<<" ";// space
        // Increasing alphabets 
        for (int j = 1; j <= i; j++) cout << char('A' + j - 1); 
        // Decreasing alphabets 
        for (int j = i - 1; j >= 1; j--) cout << char('A' + j - 1);
        cout<<endl;
    }
    return 0;
}