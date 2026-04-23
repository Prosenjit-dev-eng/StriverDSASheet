#include<iostream>
using namespace std;
void print(int n){
    if(n <= 0) return;
    cout<<"Hello world"<<endl;
    print(n-1);
}
int main()
{
    print(5);
    return 0;
}
// Time = o(n)
