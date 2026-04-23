/*Peter wants to generate some prime numbers for his cryptosystem. Help him! Your task is to generate all prime numbers between two given numbers!

Input
The input begins with the number t of test cases in a single line (t ≤ 10). In each of the next t lines there are two numbers m and n (1 ≤ m ≤ n ≤ 1e9, n-m ≤ 100000) separated by a space.

Output
For every test case print all prime numbers p such that m ≤ p ≤ n, one number per line, test cases separated by an empty line.*/
// Better 
#include<bits/stdc++.h>
using namespace std;
bool isP(int n){
    if(n == 1) return false;
    for (int i = 2; i*i <= n; i++)
    {
        if (n%i == 0)
        {
            return false;
        }
        
    }
    return true;
    
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        if (isP(n))
        {
            cout<<"yes"<<endl;
        }
        else cout<<"no"<<endl;
    }
    
    return 0;
}