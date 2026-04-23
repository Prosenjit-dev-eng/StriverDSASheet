#include<bits/stdc++.h>
using namespace std;
int floorsqrt(int n){
    int low = 1, high = n;
    while (low<=high)
    {
        long long mid = low+(high-low)/2;
        long long ans = mid*mid;
        if(ans<=(long long)n) low = mid+1;
        else high = mid - 1;
    
    }
    return high;
}
int main()
{
    int n;
    cin>>n;
    cout<<floorsqrt(n)<<endl;
    return 0;
}