#include<bits/stdc++.h>
using namespace std;
int main()
{

        int n;
        cin>>n;
        vector<int>a(n);
        for (int i = 0; i < n; i++) 
            cin >> a[i];
        int mini = INT_MAX;
        for(auto &i : a) mini = min(mini,abs(i));
        cout<<mini<<endl;
    return 0;
}