#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int M = 1e9+7;
    long long findPower(long long a, long long b){
        if(b == 0) return 1;
        long long half = findPower(a,b/2);
        if((b%2) == 0) return (half*half)%M;
        else return (a*half*half)%M;
    }
    int countGoodNumbers(long long n) {
        // if n is odd,0 1 2 3 4 
        // No of even indices = (n+1)/2
        // NO of odd indices = n/2

        // if n is even 
        // No of odd indices = (n+1)/2, bcz 7/2 = 3
        // No of even indices = n/2
        
        /* Why 5?

        For an even index, the digit can be:
        0, 2, 4, 6, 8
        There are 5 choices.
        So if there are evenCount even-index positions, the number of ways is:

        5 ^  evenCount

        Why 4?
        For an odd index, the digit must be prime:
        2, 3, 5, 7
        There are 4 choices.
        So if there are oddCount odd-index positions, the number of ways is:
        4^oddCount*/
        return (long long)(findPower(5,(n+1)/2)*findPower(4,n/2))%M;
    }
};
int main()
{
    return 0;
}