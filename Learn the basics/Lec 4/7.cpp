#include<iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false; // Prime numbers are greater than 1
    for (int i = 2; i * i <= n; i++) { // Check divisors up to sqrt(n)
        if (n % i == 0) return false; // Not prime if divisible
    }
    return true; // Prime if no divisors found
}
// Optimising approach => time = o(root n)


int main() {
    int n;
    cin >> n;

    if (isPrime(n))
        cout << n << " is a prime number." << endl;
    else
        cout << n << " is not a prime number." << endl;

    return 0;
}