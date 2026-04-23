#include<iostream>
using namespace std;
// Print 1 to n using recursion
void printDigit(int n, int i){
if(i > n) return;
cout<<i<<" ";
return printDigit(n, i+1);
}
int main()
{
    printDigit(5,1);
    return 0;
}
// Time = o(n)
