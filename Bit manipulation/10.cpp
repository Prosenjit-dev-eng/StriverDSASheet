#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> powerSet(vector<int> arr) {
    int n = arr.size();
    long int total = 1 << n;  // 2^n subsets
    vector<vector<int>> result;

    for (int mask = 0; mask < total; mask++) {
        vector<int> subset;
        for (int i = 0; i < n; i++) {
            // Non zero and set bits
            if (mask & (1 << i)) {
                subset.push_back(arr[i]);
            }
        }
        result.push_back(subset);
    }
    return result;
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> subsets = powerSet(arr);

    for (auto subset : subsets) {
        cout << "{ ";
        for (int val : subset)
            cout << val << " ";
        cout << "}" << endl;
    }

    return 0;
}
