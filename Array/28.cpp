#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
// Optimal approach
int longestConsecutiveArray(vector<int> &v, int n){
    if(n == 0) return 0;
    int longest = 1;
    unordered_set<int>s;
    for (int i = 0; i < n; i++)
    {
        s.insert(v[i]);
    }

    for(auto itr : s){
        if(s.find(itr - 1) == s.end()){
            int cnt = 1;
            int x  = itr;
            while(s.find(x+1) != s.end()){
                x = x+1;
                cnt++;
            }
            longest = max(longest,cnt);
        }
    }
    
    return longest;
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    cout<<longestConsecutiveArray(v,n)<<endl;
    return 0;
}
// Time Complexity: O(N) + O(2*N) ~ O(3*N), where N = size of the array.
// Reason: O(N) for putting all the elements into the set data structure. After that for every starting element, we are finding the consecutive elements. Though we are using nested loops, the set will be traversed at most twice in the worst case. So, the time complexity is O(2*N) instead of O(N2).