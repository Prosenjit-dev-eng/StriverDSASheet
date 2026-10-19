#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int inspace = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) cout << "*";
        for (int j = 0; j < inspace; j++) cout << " ";
        for (int j = 0; j < n - i; j++) cout << "*";

        inspace += 2;
        cout << endl;
    }

    inspace -= 4;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) cout << "*";
        for (int j = 0; j < inspace; j++) cout << " ";
        for (int j = 0; j < i; j++) cout << "*";

        inspace -= 2;
        cout << endl;
    }
    return 0;
}