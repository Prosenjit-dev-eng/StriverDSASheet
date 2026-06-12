#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        bool hasThree = false;
        // "..." is the only way to get 3 or more consecutive dots, so we check for that.
        for (int i = 0; i + 2 < n; i++) {
            if (s.substr(i, 3) == "...") {
                hasThree = true;
                break;
            }
        }

        if (hasThree) {
            cout << 2 << '\n';
        } 
        // If there are no three consecutive dots, we can count the number of dots and that will be the maximum length of consecutive dots.
        else {
            int cnt = 0;
            for (char c : s)
                if (c == '.') cnt++;
            cout << cnt << '\n';
        }
    }

    return 0;
}