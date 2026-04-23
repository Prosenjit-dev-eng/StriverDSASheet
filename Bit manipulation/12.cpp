#include<bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
        if(n == 0) return 1;
        long long exp = n;
        if(exp < 0) {
            x = 1/x;
            exp = -exp;
        }
        double half = myPow(x,exp/2);
        double res = 1;
        if(exp > 0){
            if(exp%2 == 1) res = half*half*x;
            else res = half*half;
        } 
        return res;
    }

int main()
{
    cout<<pow(3,4)<<endl;
    return 0;
}