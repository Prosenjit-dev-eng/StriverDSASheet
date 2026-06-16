#include<bits/stdc++.h>
using namespace std;

    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candy = n;
        int i = 1;
        while(i < n){
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }
            // Increasing slope -> peak
            int peak = 0;
            while(ratings[i] > ratings[i-1]){
                peak++;
                candy += peak;
                i++;
                if(i == n) return candy;
            }
            //Decreasing slope -> dip
            int dip = 0;
            while(i<n && ratings[i] < ratings[i-1]){
                dip++;
                candy += dip;
                i++;
            }
            candy -= min(peak,dip);
        }
        return candy;
    }

int main()
{
    vector<int>rat = {1,0,2};
    cout<<candy(rat)<<endl;
    return 0;
} 