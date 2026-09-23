# C++ Competitive Programming Shortcuts & Snippets

This comprehensive reference guide covers essential C++ shortcuts, STL containers, lambda functions, and boilerplate code optimized for competitive programming (CP).

---

## 1. Standard Competitive Programming Template

This template includes fast I/O setup, useful type aliases, and common macros.

```cpp
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define fi first
#define se second

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFLL = 1e18;

void solve() {
    // Your solution goes here
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```

---

## 2. Lambda Functions in CP

Lambdas are extremely useful for defining inline helper functions, custom comparators, or recursive DFS/BFS inside `main()`.

### A. Basic Lambda & Capture Clause
```cpp
// Capture all variables by reference
int factor = 2;
auto multiply = [&](int x) {
    return x * factor;
};
```

### B. Recursive Lambda (using `std::function`)
When writing recursive functions (like graph DFS) inside `main()`, you must explicitly declare the type using `std::function`:
```cpp
#include <functional>

// Inside solve():
vector<vector<int>> adj(n + 1);
vector<bool> vis(n + 1, false);

function<void(int)> dfs = [&](int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v);
    }
};

dfs(1);
```

### C. Custom Comparator Lambda (e.g., for Sorting)
```cpp
vector<pii> intervals = {{1, 3}, {2, 6}, {8, 10}};

// Sort by second element ascending, then first descending
sort(all(intervals), [](const pii& a, const pii& b) {
    if (a.se == b.se) return a.fi > b.fi;
    return a.se < b.se;
});
```

---

## 3. Maps and Hash Tables (`std::map`, `std::unordered_map`, `gp_hash_table`)

### A. `std::map` (Ordered Map)
* **Time Complexity:** $O(\log N)$ for insertion, deletion, lookup.
* **Use Case:** When elements need to stay sorted or you need ordered range queries (`lower_bound`, `upper_bound`).

```cpp
map<int, int> mp;
mp[5] = 10;

// Safe lookup with counting
if (mp.count(5)) { /* exists */ }

// Iteration
for (auto& [key, val] : mp) {
    cout << key << ": " << val << "\n";
}
```

### B. `std::unordered_map` (Unordered Hash Map)
* **Time Complexity:** $O(1)$ average, $O(N)$ worst-case (vulnerable to anti-hash tests).
* **Important CP Warning:** Always use a custom custom hash to prevent collision-based hacking on platforms like Codeforces.

```cpp
#include <chrono>

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

unordered_map<long long, int, custom_hash> safe_umap;
```

### C. Policy-Based Data Structures: `gp_hash_table` (Extremely Fast Hash Table)
Part of GNU PBDS, significantly faster than `unordered_map`.
```cpp
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

gp_hash_table<int, int, custom_hash> fast_mp;
fast_mp[100] = 42;
```

---

## 4. Useful STL Containers & Operations

### A. Priority Queue (Min-Heap / Max-Heap)
```cpp
// Max-Heap (Default)
priority_device<int> max_pq;

// Min-Heap
priority_queue<int, vector<int>, greater<int>> min_pq;
```

### B. Sets and Ordered Sets (PBDS)
If you need element indexing or finding the $k$-th smallest element in $O(\log N)$:
```cpp
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Usage:
ordered_set<int> os;
os.insert(10);
os.insert(20);

int val = *os.find_by_order(1); // 20 (0-indexed)
int rank = os.order_of_key(15);  // 1 (count of elements strictly less than 15)
```

---

## 5. Handy Utilities & Algorithms

### A. Binary Search (Lower & Upper Bound)
```cpp
vector<int> a = {1, 2, 4, 4, 4, 5, 7};

auto lb = lower_bound(all(a), 4); // Points to first '4' (index 2)
auto ub = upper_bound(all(a), 4); // Points to element after last '4' (index 5, value 5)

int idx = lb - a.begin();
```

### B. Numeric Operations (`__builtin` functions)
```cpp
int n = 9; // Binary: ...00001001
int set_bits = __builtin_popcount(n);        // Count set bits (2)
int set_bits_ll = __builtin_popcountll(1LL); // For long long

int lead_zeros = __builtin_clz(n);           // Count leading zeros
int trail_zeros = __builtin_ctz(n);          // Count trailing zeros (0)
```

### C. Coordinate Compression
```cpp
vector<int> a = {100, 20, 20, 5000, 20};
vector<int> b = a;

sort(all(b));
b.erase(unique(all(b)), b.end());

for (int& x : a) {
    x = lower_bound(all(b), x) - b.begin(); // Replaced with compressed ranks: 0, 1, 1, 2, 1
}
```