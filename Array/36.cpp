#include<iostream>
using namespace std;

// Function to calculate nCr (n choose r)
int binomialCoeff(int n, int r) {
    int res = 1;
    if (r > n - r) r = n - r;
    for (int i = 0; i < r; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

void printPascalTriangle(int n) {
    for (int line = 0; line < n; line++) {
        // Print leading spaces for alignment
        for (int space = 0; space < n - line - 1; space++) {
            cout << "  ";
        }
        for (int i = 0; i <= line; i++) {
            cout << binomialCoeff(line, i) << "   ";
        }
        cout << endl; 
    }
}

int main() {
    int n = 5;
    printPascalTriangle(n);
    return 0;
}
