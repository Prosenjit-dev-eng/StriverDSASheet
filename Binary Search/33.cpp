#include<bits/stdc++.h>
using namespace std;
    int startStation(vector<int> &gas, vector<int> &cost) {
        //  code here
        int n = gas.size();
        int totGas = 0, totCost = 0,start = 0, curGas = 0;
        for(int i = 0; i < n; i++){
            totGas += gas[i];
            totCost += cost[i];
            curGas += gas[i] - cost[i];
            if(curGas < 0){
                curGas = 0;
                start = i+1;
            }
        }
        return totGas < totCost ? -1 : start;  
    }
int main()
{
    vector<int>gas = {1,2,3,4,5};
    vector<int>cost = {3,4,5,1,2};
    cout<<startStation(gas,cost)<<endl;
    return 0;
}