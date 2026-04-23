#include <bits/stdc++.h>
using namespace std;
void add(int &subset,int x)
{
    subset = (subset ^ (1 << (x-1)));

}
void remove(int &subset, int x)
{
    subset = (subset ^ (1 << (x-1)));
}
void display(int subset, int n)
{
    // int n = __builtin_popcount(n);
    for (int bit = 0; bit < n; bit++)
    {
        if (subset & (1 << bit))
        {
            cout << bit + 1 << " ";
        }
    }
}
int main()
{
    int set = 15;
    int n = 10;
    display(set, n);
    remove(set,2);
    display(set,n);
    add(set,5);
    display(set,n);

    return 0;
}