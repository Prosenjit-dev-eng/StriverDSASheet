#include<bits/stdc++.h>
using namespace std;
struct Data{
    int s;
    int e;
    int pos;
};
// The end is comparing in it increasing order

bool comp(Data val1, Data val2){
    return val1.e<val2.e;
}
void N_meetings(int start[],int end[],int n){
    vector<Data>arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i].s = start[i];
        arr[i].e = end[i];
        arr[i].pos = i+1;
        
    }
    sort(arr.begin(),arr.end(),comp);
    // vector<int> position(n, arr[0].pos);  // ❌ This creates a vector of size n, all with arr[0].pos
    vector<int>position;
    position.push_back(arr[0].pos);
    int cnt = 1;// bcz of arr[0].pos
    int free = arr[0].e;
    for (int i = 1; i < n; i++)
    {
        if (arr[i].s>=free)
        {
            cnt++;
            free = arr[i].e;
            position.push_back(arr[i].pos);
        }

    }
    cout<<"The order in which the meetings will be performed is "<<endl;
      for (int i = 0; i < position.size(); i++) {
         cout << position[i] << " ";
      }
}
int main()
{
   int n = 6;
   int start[] = {1,3,0,5,8,5};
   int end[] = {2,4,5,7,9,9};
   N_meetings(start,end,n);
    return 0;
}