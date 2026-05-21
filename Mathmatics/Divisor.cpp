#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vi findDivisors(int n){
    vi res;
    for(int i = 1; i*i <= n; i++){
        if(n % i == 0){
            res.push_back(i);
            res.push_back(n/i);
        }
    }
    return res;
}
int main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    vi res = findDivisors(n);
    for(int &i : res){
        cout<<i<<" ";
    }
    return 0;
}