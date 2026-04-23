#include<bits/stdc++.h>
using namespace std;
// set the ith bit of a number
void setIthBit(int &n, int i)   
{
    n = n | (1 << i);
}
void clearIthBit(int &n, int i) {
    n = n & ~(1 << i);
}
void toggleIthBit(int &n, int i) {
    n = n ^ (1 << i);
}
int main()
{
    int num = 13; // 1101 in binary
    int i = 1;
    setIthBit(num, i);
    cout << "Number after setting " << i << "-th bit: " << num << endl;
    clearIthBit(num, i);
    cout << "Number after clearing " << i << "-th bit: " << num << endl;
    return 0;
}