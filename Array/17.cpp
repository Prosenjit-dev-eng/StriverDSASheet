// Striver
#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        //calculate the prefix sum till index i:
        sum += a[i];

        // if the sum = k, update the maxLen:
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k:
        long long rem = sum - k;

        //Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];// like  6 - 3, bcz preSumMap[rem] returns the value which is the index of the prefix sum.
            maxLen = max(maxLen, len);
        }

        //Finally, update the map checking the conditions: if it has negative values, we don't want to update it again.
        // We only want the first occurrence of the prefix sum.
        // If it is already present, we do not update it again.
        if (preSumMap.find(sum) == preSumMap.end()) {//If .find(sum) returns .end(), that means the key isn’t there yet, so we can safely insert it.
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}

int main()
{
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}


