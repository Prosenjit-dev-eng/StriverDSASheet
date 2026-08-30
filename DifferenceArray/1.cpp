// LC-2381
#include<bits/stdc++.h>
/*
(i) Here 0 = -1 & 1 = +1 , for difference array we store it , then we do cumulative sum to find what I have to add for each character
(ii) In Diff array for [L,R] => A[l] += x, and A[r+1] -= x, the we do cumsum
*/
using namespace std;
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();

        vector<int> diffArr(n, 0);

        // Difference array
        for (auto &it : shifts) {
            int x = (it[2] == 0) ? -1 : 1;

            diffArr[it[0]] += x;

            if (it[1] + 1 < n)
                diffArr[it[1] + 1] -= x;
        }

        // Prefix sum = actual shift at each index
        vector<int> cumsum(n, 0);

        cumsum[0] = diffArr[0];

        for (int i = 1; i < n; i++) {
            cumsum[i] = cumsum[i - 1] + diffArr[i];
        }

        // Apply shifts
        for (int i = 0; i < n; i++) {
            int k = cumsum[i] % 26;

            if (k >= 0) {
                s[i] = 'a' + (s[i] - 'a' + k) % 26;
            }
            else {
                s[i] = 'a' + (s[i] - 'a' + k + 26) % 26;
            }
        }

        return s;
    }
int main()
{
    string s = "abc";
    vector<vector<int>> shifts = {
        {0,1,0},{1,2,1},{0,2,1}
    };
    cout<<shiftingLetters(s,shifts)<<endl;
    return 0;
}