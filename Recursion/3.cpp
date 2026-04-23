#include<bits/stdc++.h>
using namespace std;
void f(int i, int n){
    if(i > n) return;
    cout<<i<<endl;
    f(i+1,n);
}
// Backtracking => Printing will be done at last
void f2(int i, int n){
    if(i<1) return;
    f2(i-1,n);
    cout<<i<<" ";
}
int main()
{
    int n = 5;
    f(1,n);
    cout<<endl;
    f2(n,n);
    return 0;
}