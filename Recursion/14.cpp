#include <bits/stdc++.h>
using namespace std;

set<vector<int>> s; // To avoid duplicates

void getAllCombinations(vector<int>& arr, int idx, int target, vector<vector<int>>& ans, vector<int>& combin) {
    int n = arr.size();
    if (target == 0) {
        if (s.find(combin) == s.end()) {
            ans.push_back(combin);
            s.insert(combin);
        }
        return;
    }
    if (idx == n || target < 0) return;

    // Pick once
    combin.push_back(arr[idx]);
    getAllCombinations(arr, idx + 1, target - arr[idx], ans, combin);

    // Pick multiple times
    getAllCombinations(arr, idx, target - arr[idx], ans, combin);

    // Backtrack
    combin.pop_back();

    // Not pick
    getAllCombinations(arr, idx + 1, target, ans, combin);
}

vector<vector<int>> combinationSumII(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end()); // Optional but helps in skipping duplicates efficiently
    s.clear(); // Clear the set to avoid stale values
    vector<vector<int>> ans;
    vector<int> combin;
    getAllCombinations(arr, 0, target, ans, combin);
    return ans;
}

int main() {
    vector<int> arr = {1, 1, 1, 2, 2};
    int target = 4;

    vector<vector<int>> result = combinationSumII(arr, target);

    cout << "Unique combinations that sum to " << target << ":\n";
    for (const auto& comb : result) {
        for (int val : comb) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}
