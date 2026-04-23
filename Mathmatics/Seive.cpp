// The problem statement is really simple. There are some queries. You are to give the answers.

// Input
// An integer stating the number of queries Q (equal to 50000), and Q lines follow, each containing one integer K between 1 and 5000000 inclusive.

// Output
// Q lines with the answer of each query: the Kth prime number.
#include<bits/stdc++.h>
using namespace std;
bool isPrime[90000001];// Why bool , it has 1 byte and int has 4 bytes
void seive(){
    int maxN = 90000000;
    for (int i = 1; i <= maxN; i++)
    {
        isPrime[i] = 1;
    }
    isPrime[0] = isPrime[1] = 1;
    for (int i = 2; i*i <= maxN; i++)
    {
        if (isPrime[i])
        {
           for (int j = i*i; j <= maxN; j+=i)
            {
                isPrime[i] = 0;
            }
            
        }
        
    }
    

    
}

int main()
{
    int t;
    cin>>t;
    seive();
    while (t--)
    {
        int n;
        cin>>n;
        cout<<isPrime[n-1]<<endl;
    }
    return 0;
}