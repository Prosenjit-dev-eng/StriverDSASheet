#include<bits/stdc++.h>
using namespace std;
struct Item{
    int val;
    int wt;
};
// The unit wt is comparing in it Decreasing order
bool comp(Item val1, Item val2){
    double r1 = (double)(val1.val)/(double)(val1.wt);
    double r2 = (double)(val2.val)/(double)(val2.wt);
    return r1 > r2;
}
double fractionalKnapsack(int W, Item arr[], int n){
    sort(arr, arr + n, comp);
    double total = 0.0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i].wt<=W){
            total += arr[i].val;
            W -= arr[i].wt; 
        }
        else
        {
            total += (double)(arr[i].val)/(arr[i].wt)*W;
            break;
        }
        
    }
    return total;
}
int main()
{
    int W = 50;
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Maximum value in Knapsack = " << fractionalKnapsack(W, arr, n) << endl;
    return 0;
}