#include<iostream>
#include<math.h>
using namespace std;
// Brute force => time = o(n)
/*void printDivisors(int n){
    for (int i = 1; i <= n; i++)
    {
        if (n%i == 0)
        {
            cout<<i<<" ";
        }
        
    }
    
}*/
// Optimising approach => time = o(root n)
void printDivisors(int n){
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n%i == 0)
        {
            cout<<i<<" ";
            cout<<endl;
            if((n/i)!=i)
            cout<<(n/i)<<" ";
        }
        
    }
}
int main()
{
    int n;
    cin>>n;

    printDivisors(n);

    return 0;
}