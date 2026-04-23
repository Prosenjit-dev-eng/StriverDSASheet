#include<bits/stdc++.h>
using namespace std;
// I th bit set or not
bool isIthBitSet(int n, int i)
{
    return (n & (1 << i)) != 0;
}
int main()
{
    int n, i;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Enter the bit position to check: ";
    cin >> i;
    // 💡 1. Numbers Are Stored in Binary Internally
    // In C++ (and all modern programming languages), integers like 13 are stored in binary form inside the computer, even if you write them in decimal.
    if (isIthBitSet(n, i))
        cout << "The " << i << "th bit is set." << endl;
    else
        cout << "The " << i << "th bit is not set." << endl;

    return 0;
}