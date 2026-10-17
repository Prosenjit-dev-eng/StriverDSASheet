#include<bits/stdc++.h>
using namespace std;
int largestDigit(int n) {
        if(n == 0) return 0;
        int ld = -1;
        while(n > 0){
            int d = n%10;
            ld = max(ld,d);
            n/=10;
        }
    return ld;
}
int main()
{
    cout<<largestDigit(12345)<<endl;
    return 0;
}