#include<bits/stdc++.h>
using namespace std;
 int countOddDigit(int n) {
        int cnt = 0;
        while(n > 0){
            int d = n%10;
            if(d%2) cnt++;
            n/=10;
        }
        return cnt;
    }
int main()
{
    cout<<countOddDigit(1234)<<endl;
    return 0;
}