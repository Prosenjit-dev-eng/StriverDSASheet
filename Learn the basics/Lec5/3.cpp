#include<iostream>
using namespace std;
// print n to 1
void printDigit(int n, int i){
    if(i < 1) return;
    cout<<i<<" ";
    return printDigit(n,i-1);
    }

int main()
{
    printDigit(5,5);
    return 0;
}
// Time = o(n)