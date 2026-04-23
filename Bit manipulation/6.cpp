#include<bits/stdc++.h>
using namespace std;
bool isPowerOf2(int n){
    if((n & (n-1)) == 0) return true;// (n & (n-1)) = 100000 like that , 8 = 1000 & 1000 = 0000
    else return false;
}
int main()
{
    if(isPowerOf2(8)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}