#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        // Special overflow case
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        bool sign = true;
        if(dividend >= 0 && divisor < 0) sign = false;
        if(dividend < 0 && divisor > 0) sign = false;
        ll n = llabs((ll)dividend); ll d = abs((ll)divisor);
        ll ans = 0;
        while(n >= d){
            int cnt = 0;
            while(n >= (d<<(cnt+1)) && (d<<(cnt+1)) > 0){
                cnt++;
            }
            n = n - (d<<cnt);
            ans += (1LL<<cnt);
        } 

        return sign ? ans : -ans; 

    }
int main()
{
    int  dividend = 22, divisor = 7;
    cout<<divide(dividend, divisor)<<endl;
    return 0;
}