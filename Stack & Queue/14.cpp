#include<bits/stdc++.h>
using namespace std;
// NSE
vector<int> nextSmallerElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, -1);// bcz if no smaller element found then -1
    stack<int> st;
    // Traverse from right to left
    // We will use a stack to keep track of the next smaller elements
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            ans[i] = st.top();
        }
        else {
            ans[i] = -1;
        }
        st.push(arr[i]);
    }
    
    
    return ans;
}
int main()
{
    vector<int> arr = {4, 8, 5, 2, 25};
    vector<int> result = nextSmallerElement(arr);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}