#include<iostream>
using namespace std;
// Count Digits
int countDigit(int n) {
    int count = 0, digit = 0;
    while(n!=0){
        digit = n%10;
        count++;
        n/=10;
    }
    return count;
}
int main()
{
    int n;// Time = O(d) => d = no. of digits
    cin>>n;

    cout<<countDigit(n)<<endl;
    return 0;
}