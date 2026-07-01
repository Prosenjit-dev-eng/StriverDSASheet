#include <bits/stdc++.h>
using namespace std;

vector<int> zFunction(string s) {
    int n = s.size();
    vector<int> z(n);

    int l = 0, r = 0;

    for (int i = 1; i < n; i++) {

        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);

        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;

        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    return z;
}

vector<int> search(string text, string pattern) {

    string s = pattern + "$" + text;

    vector<int> z = zFunction(s);

    vector<int> ans;

    int m = pattern.size();

    for (int i = m + 1; i < s.size(); i++) {// m+1 due to '$'

        if (z[i] == m)
            ans.push_back(i - m - 1);
    }

    return ans;
}

int main() {

    string text = "abxabcabc";
    string pattern = "abc";

    vector<int> ans = search(text, pattern);

    for (int x : ans)
        cout << x << " ";

    return 0;
}