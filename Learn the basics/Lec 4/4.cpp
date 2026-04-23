#include<iostream>
using namespace std;
int main()
{
    int num1,num2;
    cin>>num1>>num2;

    int n1 = num1, n2 = num2, rem = 0, gcd, lcm;
    while (n2 != 0)
    {
        rem = n1 % n2;
        n1 = n2;
        n2 = rem;
    }
    gcd = n1;
    lcm = (num1*num2)/gcd;
    cout<<"GCD: "<<gcd<<endl;
    cout<<"LCM: "<<lcm<<endl;

    return 0;
}
// Time = O(d) => d = no. of digits