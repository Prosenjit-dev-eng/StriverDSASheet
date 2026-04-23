#include<bits/stdc++.h>
using namespace std;
vector<int> findNSEI(vector<int>arr)
{
    int n = arr.size();
    vector<int> nsei(n);
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
        {

            s.pop();
        }
        nsei[i] = s.empty() ? n : s.top();
        s.push(i);
    }
    return nsei;
}
vector<int> findPSEI(vector<int>arr)
{
    int n = arr.size();
    vector<int> psei(n);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] > arr[i])
        {

            s.pop();
        }
        psei[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    return psei;
}
int subarraymin(vector<int> arr){
    int total = 0;
    int mod = (int)(1e9 + 7);
    int n = arr.size();
    vector<int> nsei = findNSEI(arr);
    vector<int> psei = findPSEI(arr);
    for (int i = 0; i < n; i++)
    {
        int left = i - psei[i];
        int right = nsei[i] - i;
        total = (total + (left * right * 1LL * arr[i]) % mod) % mod;
    }
    return total;
}
int main()
{
    vector<int> arr = {3, 1, 2, 4};
    cout << subarraymin(arr) << endl;
    return 0;
}