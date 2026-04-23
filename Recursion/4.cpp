#include<bits/stdc++.h>
using namespace std;
void f(int i, int n){
    if(n == 0) return;
    cout<<n<<endl;
    f(i+1,n-1);
}
void f3(int i, int n){
    if(i>n) return;
    f3(i+1,n);
    cout<<i<<" ";
}

int main()
{
    int n = 5;
    f(1,n);
    f3(1,n);
    
    return 0;
}