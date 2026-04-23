#include<bits/stdc++.h>
using namespace std;
// Jump game -I
bool canJumpI(vector<int>arr){
    int maxIdx = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if(i>maxIdx) return false;
        maxIdx = max(maxIdx,i+arr[i]);
    }
    return true;
}
int main()
{
    vector<int>arr = {3, 2, 1, 0, 4};
    cout<<canJumpI(arr)<<endl;
    return 0;
}