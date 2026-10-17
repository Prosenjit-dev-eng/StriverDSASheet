#include<bits/stdc++.h>
using namespace std;

bool canWePlaced(vector<int>&v, int n, int dist, int cows){// Distance we get from mid
    int count = 1, last = v[0];//It should be count = 1 since one cow is already placed at the beginning.
    for (int i = 1; i < n; i++)// index starts from 1
    {
        if(v[i] - last >= dist){// |c1 - c2|
            count++;
            last = v[i];
        }
    }
    if(count >= cows) return true;
    else return false;
}

int agressiveCows(vector<int>&v, int n,int cows){
    sort(v.begin(),v.end());
    int low = 1, high = v[n-1] - v[0];
    while (low<=high)
    {
        int mid = low + (high - low)/2;
        
        if(canWePlaced(v,n,mid,cows)) low = mid+1;// because largest minimum distance
        else high = mid - 1;
    }
    return high;
}
int main()
{
        int n;
    cin>>n;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    int cows;
    cin>>cows;
    cout<<agressiveCows(v,n,cows)<<endl;
    return 0;
}