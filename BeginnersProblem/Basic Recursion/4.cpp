#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n, int i = 2) {
    // Base cases
    if (n <= 1) return false;
    if (i * i > n) return true;

    if (n % i == 0) return false;

    return isPrime(n, i + 1);
}
int main()
{
    cout << isPrime(17) << endl; // Output: 1 (true)
    cout << isPrime(15) << endl; // Output: 0 (false)
    return 0;
}