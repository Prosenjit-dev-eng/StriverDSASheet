#include<bits/stdc++.h>
using namespace std;
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
    //    unordered_map<int,unordered_set<int>>mp;// row to col reserved seats
        unordered_map<int,int>mp;
       for(auto &it:reservedSeats)
       {
            if(it[1] >= 2 && it[1] <= 9)
            {
                mp[it[0]] |= (1 << (it[1]));
            }
       }
       // Empty seats
       int res = (n-mp.size())*2;
       for(auto &it:mp)
       {

            int reserved = it.second;
            
            // Bitmasks for the specific seat groups
            // Left (2,3,4,5) = 0000111100 in binary = 60
            // Middle (4,5,6,7) = 0011110000 in binary = 240
            // Right (6,7,8,9) = 1111000000 in binary = 960
            
            bool grA = (reserved & 60) == 0;
            bool grB = (reserved & 240) == 0;
            bool grC = (reserved & 960) == 0;
            
            if (grA && grC) {
                res += 2;
            } else if (grA || grB || grC) {
                res += 1;
            }
       }
       return res;
    }
int main()
{
    return 0;
}