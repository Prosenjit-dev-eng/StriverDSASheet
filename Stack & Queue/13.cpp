#include<bits/stdc++.h>
using namespace std;
// NGE2
vector<int> nextGreaterElement2(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, -1);// bcz if no greater element found then -1
    stack<int> st;
    // Traverse from right to left
    // We will use a stack to keep track of the next greater elements
    // We will traverse the array twice to handle circular nature
    // This is done by iterating from 2*n - 1 to 0 and
    for (int i = 2*n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i % n]) {
            st.pop();
        }
    if(i<n){
        if (!st.empty()) {
            ans[i % n] = st.top();
        }
        else {
            ans[i % n] = -1;
        }
    }
    st.push(arr[i % n]);
    }
    
    
    return ans;
}
int main()
{
    vector<int> arr = {2,10,12,1,11};
    vector<int> result = nextGreaterElement2(arr);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}