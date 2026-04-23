#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void sortKSortedArray(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int n = arr.size();
    int index = 0;

    // Step 1: push first k+1 elements
    for (int i = 0; i < k + 1 && i < n; i++)
        pq.push(arr[i]);

    // Step 2: process the rest
    for (int i = k + 1; i < n; i++) {
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }

    // Step 3: empty the heap
    while (!pq.empty()) {
        arr[index++] = pq.top();
        pq.pop();
    }
}

int main() {
    vector<int> nums = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    sortKSortedArray(nums, k);

    cout << "Sorted array: ";
    for (int x : nums)
        cout << x << " ";
}
