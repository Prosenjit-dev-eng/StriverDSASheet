#include<bits/stdc++.h>
using namespace std;
bool isOdd(int n){
    if((n>>2)!=1) return false;
    return true;
}
int main()
{
    int n = 7;
    if(isOdd(n)) cout<<"Odd"<<endl;
    else cout<<"Even"<<endl;
    return 0;
}