#include<bits/stdc++.h>
using namespace std;
int sumArray(vector<int>& arr, int n) {
    // Base case
    if (n == 0)
        return 0;

    // Recursive case
    return arr[n - 1] + sumArray(arr, n - 1);
}
int main()
{
    return 0;
}
