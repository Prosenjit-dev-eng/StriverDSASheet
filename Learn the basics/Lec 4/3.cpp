#include<iostream>
using namespace std;
// Palindrome of number
bool isPalindrome(int x) {
    // now for negative , handle the case also
    if(x<0) return false;
    int original = x;
    int digit = 0, sum = 0;
    while(x!=0){
        digit = x%10;
        sum = sum*10 + digit;
        x/=10;
    }
    // it's wrong because x is alreday 0, so store it into original
    if(sum == original) return true;
    return false;
}
int main()
{
    int n;
    cin>>n;

    cout<<isPalindrome(n)<<endl;
    return 0;
}
// Time = O(d) => d = no. of digits