#include<bits/stdc++.h>
using namespace std;

double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<pair<int,int>>vec(n);
        for(int i = 0; i < n; i++){
            vec[i] = {val[i],wt[i]};
        }
        // [], here we write the external variables
        // In a lambda, external variables are variables that are declared outside the lambda body but are used inside the lambda.
        /* 
int x = 10;

auto lambda = [x](int y){
    return x + y;
}; */
        auto lambda = [](pair<int,int>&p1, pair<int,int>&p2){
            return (1.0*p1.first)/p1.second > (1.0*p2.first)/p2.second;// 1.0 coz of fractional values
        };
        
        sort(vec.begin(),vec.end(),lambda);
        double res = 0.0;
        for(int i = 0; i < n; i++){
            if(vec[i].second <= capacity){
                res += vec[i].first;
                capacity -= vec[i].second;
            }
            else{
                res += (1.0*vec[i].first)/vec[i].second * capacity;
                break;
            }
        }
        return res;
    }


int main()
{
    vector<int>val = {60, 100, 120};
    vector<int>wt = {10, 20, 30};
    int capacity = 50;
    cout<<fractionalKnapsack(val,wt,capacity);
    return 0;
}