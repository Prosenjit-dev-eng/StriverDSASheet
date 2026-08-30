#include<bits/stdc++.h>
using namespace std;
bool stoneGameIX(vector<int>& stones) {
    int c0 = 0,c1 = 0,c2 = 0;
    for(auto &s : stones){
        if(s%3 == 0) c0++;
        else if(s%3 == 1) c1++;
        else c2++;
    }
    if(c0%2 == 0) return c1 > 0 && c2 > 0;//even
    return abs(c1-c2) >= 3;

}

int main()
{
    return 0;
}