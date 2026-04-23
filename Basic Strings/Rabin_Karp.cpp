#include <bits/stdc++.h>
using namespace std;

#define d 256  // number of characters in input alphabet

void rabinKarp(string txt, string pat, int q) {
    int n = txt.size();
    int m = pat.size();
    int i, j;
    int p = 0; // hash for pattern
    int t = 0; // hash for text
    int h = 1;

    // The value of h would be "pow(d, m-1) % q"
    // H=(A.d3+B.d2+C.d1+D) mod q
    // If we used m instead of m−1

// We’d subtract 
// 𝐴
// ⋅
// 𝑑
// 3
// A⋅d
// 3
// , which is too big — the exponents wouldn’t line up correctly with the sliding window.
    for (i = 0; i < m-1; i++)
        h = (h * d) % q;

    // Calculate hash value for pattern and first window of text
    for (i = 0; i < m; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    // Slide the pattern over text
    for (i = 0; i <= n - m; i++) {
        // If hash values match, check characters
        if (p == t) {
            for (j = 0; j < m; j++) {
                if (txt[i+j] != pat[j])
                    break;
            }
            if (j == m) cout << "Pattern found at index " << i << endl;
        }

        // Compute hash for next window
        if (i < n - m) {
            t = (d * (t - txt[i]*h) + txt[i+m]) % q;
            if (t < 0) t = (t + q);
        }
    }
}

int main() {
    string txt = "GEEKS FOR GEEKS";
    string pat = "GEEK";
    int q = 101; // prime number
    rabinKarp(txt, pat, q);
    return 0;
}
