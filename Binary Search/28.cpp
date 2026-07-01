#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int nThRoot(int n, int m){
    int l = 1, h = m;
    while(l <= h){
        ll mid = l + (h-l)/2;
        ll ans = 1;
        for (int i = 0; i < n; i++)
        {
            ans *= mid;
            if(ans > m) break; // avoid unnecessary multiplication
        }
        if(ans == m) return mid;
        else if(ans < m) l = mid+1;
        else h = mid - 1;
    }
    return -1;
}
int main()
{
    cout<<nThRoot(3,81)<<endl;
    return 0;
}