#include<iostream>
using namespace std;
// Reverse
int reverse(int x) {
    int digit = 0, sum = 0;
    while(x!=0){
        digit = x%10;
        sum = sum*10 + digit;
        x/=10;
    }
    return sum;
}
int main()
{
    int n;
    cin>>n;

    cout<<reverse(n)<<endl;
    return 0;
}
// Time = O(d) => d = no. of digits