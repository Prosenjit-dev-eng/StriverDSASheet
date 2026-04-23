#include<bits/stdc++.h>
using namespace std;
void f(int i, int n){
    if(i > n) return;
    cout<<"Hello"<<endl;
    f(i+1,n);
}
int main()
{
    int n = 5;
    f(1,n);
    return 0;
}
// Tc = o(n)
// tc = o(n)