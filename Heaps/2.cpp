#include<bits/stdc++.h>
using namespace std;
int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;// Minheap
        int n = nums.size();

        for(int i = 0; i < k; i++){
            pq.push(nums[i]);
        }
        for(int j = k; j < n; j++){
            int ele = nums[j];
            if(ele > pq.top()){
                pq.pop();
                pq.push(ele);
            }
        }
        return pq.top();
}
int findKthSmallest(vector<int>& nums, int k) {
        priority_queue<int> pq;// Maxheap
        int n = nums.size();

        for(int i = 0; i < k; i++){
            pq.push(nums[i]);
        }
        for(int j = k; j < n; j++){
            int ele = nums[j];
            if(ele < pq.top()){
                pq.pop();
                pq.push(ele);
            }
        }
        return pq.top();
    }
int main()
{
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << findKthLargest(nums, k) << endl; // Output: 5
    cout << findKthSmallest(nums, k) << endl; // Output: 2
    return 0;
}