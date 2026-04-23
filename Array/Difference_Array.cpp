#include<bits/stdc++.h>
using namespace std;
// Leetcode 370(Premimum)
// Range Addition
vector<int> getModifiedArray(int length, vector<vector<int>>&queries){
    vector<int>d(length,0);
    for(auto &e: queries){
        int l = e[0], r = e[1], x = e[2];
        d[l] += x;
        if((r+1) < length) d[r+1] -= x;
    }
    
    for (int i = 1; i < length; i++)
    {
        d[i] += d[i-1];
    }
    return d;
}

int main()
{
    int length = 5;
    vector<vector<int>>queries = {{1,3,2},{2,4,3},{0,2,-2}};
    vector<int>rangeAddition = getModifiedArray(length,queries);
    for (int i = 0; i < length; i++)
    {
        cout<<rangeAddition[i]<<" ";
    }
    
    return 0;
}