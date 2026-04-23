#include<bits/stdc++.h>
using namespace std;
int noOfFlipped(int start, int goal){
    int n = (start^goal);
    // No of set bits
    int cnt = 0;
    while (n)
    {
        n = n&(n-1);
        cnt++;
    }
    return cnt;
}
int main()
{
    int start, goal;
    cin>>start>>goal;
    cout<<noOfFlipped(start,goal)<<endl;

    return 0;
}