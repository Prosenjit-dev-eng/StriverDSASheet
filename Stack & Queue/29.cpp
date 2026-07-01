#include<bits/stdc++.h>
using namespace std;

    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> left(n), ans(n + 1, INT_MIN);
        stack<int> st;

        // Previous Smaller
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Smaller and update answer immediately
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            int right = st.empty() ? n : st.top();
            int len = right - left[i] - 1;

            ans[len] = max(ans[len], arr[i]);
            st.push(i);
        }

        // Fill missing answers
        for (int i = n - 1; i >= 1; i--)
            ans[i] = max(ans[i], ans[i + 1]);

        ans.erase(ans.begin()); // remove index 0
        return ans;
    }
int main()
{
    vector<int>arr = {10, 20, 30, 50, 10, 70, 30};
    vector<int> res = maxOfMins(arr);
    for(auto &r : res) cout<<r<<" ";
    return 0;
}