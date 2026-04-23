#include<bits/stdc++.h>
using namespace std;
int removeTheLastSetBit(int n){
   return (n & (n-1));
}
int main()
{
    int n = 12;
    cout<<removeTheLastSetBit(n)<<endl;
    return 0;
}