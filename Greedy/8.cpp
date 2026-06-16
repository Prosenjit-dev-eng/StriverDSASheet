#include<bits/stdc++.h>
using namespace std;
struct Job{
    int id;
    int deadline;
    int profit;
};

bool comp(Job& val1, Job& val2){
    return val1.profit>val2.profit;
}
pair<int,int> jobSequence(Job arr[], int n){ 

    sort(arr,arr+n,comp);
    int cnt = 0;
    int totProfit = 0;
    int maxDeadline = -1;
    for(int i = 0; i < n; i++) maxDeadline = max(maxDeadline,arr[i].deadline);
    vector<int> slot(maxDeadline+1, -1);
    for (int i = 0; i < n; i++)
    {
        for(int j = arr[i].deadline; j > 0; j--){
            if(slot[j] == -1){
                slot[j] = arr[i].id;
                cnt++;
                totProfit += arr[i].profit;
                break;
            }
        }

    }
    return {cnt,totProfit};

}
int main()
{
   int n = 4;
   Job arr[] = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}}; 
   pair<int,int>p = jobSequence(arr,n);
   cout<<p.first<<" "<<p.second<<endl;
    return 0;
}