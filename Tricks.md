# Blueprint of palindromic string as bottom up
        // isPalindrome[i][j] = whether s[i...j] is palindrome
        vector<vector<bool>> isPalindrome(
            n, vector<bool>(n, false)
        );

        // Build palindrome table
        for (int L = 1; L <= n; L++) {

            for (int i = 0; i + L <= n; i++) {

                int j = i + L - 1;
                // String length of 1
                if (L == 1) {
                    isPalindrome[i][j] = true;
                }
                // Length of 2
                else if (L == 2) {
                    isPalindrome[i][j] = (s[i] == s[j]);
                }
                else {
                    isPalindrome[i][j] =
                        (s[i] == s[j] &&
                         isPalindrome[i + 1][j - 1]);
                }
            }
        }
# Difference Array

## 1. What is a Difference Array?

A **Difference Array** is a technique used to efficiently perform **multiple range updates** on an array.

Instead of updating every element in a range `[l, r]`, we mark only the **starting and ending boundaries**.

### Main idea

For an update:

```text
[l, r] += x
```

we do:

```text
diff[l]     += x
diff[r + 1] -= x
```

Then we recover the final array using a **prefix sum** of `diff`.

---

## 2. Why do we need it?

Suppose:

```text
arr = [0, 0, 0, 0, 0]
```

We want:

```text
Add 5 to indices [1, 3]
```

### Normal approach

Update each element:

```text
[0, 5, 5, 5, 0]
```

Time: `O(r-l+1)`

If there are many updates, this can become expensive.

### Difference Array approach

Instead of changing all elements:

```text
diff[1] += 5
diff[4] -= 5
```

Then take prefix sums.

---

## 3. Formula

For range update:

```text
[l, r] += x
```

use:

```cpp
diff[l] += x;
diff[r + 1] -= x;
```

After all updates:

```cpp
arr[0] = diff[0];

for (int i = 1; i < n; i++) {
    arr[i] = arr[i - 1] + diff[i];
}
```

Equivalently:

```cpp
int running = 0;

for (int i = 0; i < n; i++) {
    running += diff[i];
    arr[i] = running;
}
```

---

# 4. Dry Run

Initial:

```text
arr  = [0, 0, 0, 0, 0]
```

Update:

```text
[1, 3] += 5
```

### Step 1: Mark boundaries

```text
diff[1] += 5
diff[4] -= 5
```

So:

```text
diff = [0, 5, 0, 0, -5]
```

### Step 2: Prefix sum

| Index | `diff[i]` | Running Sum | Final `arr[i]` |
| ----: | --------: | ----------: | -------------: |
|     0 |         0 |           0 |              0 |
|     1 |         5 |           5 |              5 |
|     2 |         0 |           5 |              5 |
|     3 |         0 |           5 |              5 |
|     4 |        -5 |           0 |              0 |

Final:

```text
arr = [0, 5, 5, 5, 0]
```

---

# 5. Multiple Updates

Suppose:

```text
arr = [0, 0, 0, 0, 0]
```

Operations:

```text
[1, 3] += 5
[2, 4] += 2
[0, 2] += 3
```

### Mark the updates

| Update       | `diff[l] += x` | `diff[r+1] -= x` |
| ------------ | -------------: | ---------------: |
| `[1,3] += 5` | `diff[1] += 5` |   `diff[4] -= 5` |
| `[2,4] += 2` | `diff[2] += 2` |   `diff[5] -= 2` |
| `[0,2] += 3` | `diff[0] += 3` |   `diff[3] -= 3` |

Using an extra position:

```text
diff = [3, 5, 2, -3, -5, -2]
```

Prefix sum:

| Index | Diff | Running Sum | Final Value |
| ----: | ---: | ----------: | ----------: |
|     0 |    3 |           3 |           3 |
|     1 |    5 |           8 |           8 |
|     2 |    2 |          10 |          10 |
|     3 |   -3 |           7 |           7 |
|     4 |   -5 |           2 |           2 |

Therefore:

```text
Final array = [3, 8, 10, 7, 2]
```

---

# 6. Generic C++ Template

```cpp
vector<long long> diff(n + 1, 0);

for (auto &[l, r, x] : queries) {
    diff[l] += x;
    diff[r + 1] -= x;
}

long long running = 0;

for (int i = 0; i < n; i++) {
    running += diff[i];
    arr[i] += running;
}
```

If the initial array is all zeros, simply:

```cpp
arr[i] = running;
```

---

# 7. Complexity

For `Q` range updates:

### Normal approach

```text
Time: O(Q × N)        (worst case)
```

### Difference Array

```text
Apply updates: O(Q)
Build final array: O(N)

Total: O(N + Q)
Space: O(N)
```

This is the main reason we use Difference Array.

---

# 8. When should I think of Difference Array?

Whenever you see:

* Many range updates
* Add/subtract a value over `[l, r]`
* "Perform Q operations"
* "Increment every element from L to R"
* "Apply updates to ranges"
* Need the final array after all updates

Think:

```text
Range Update
     ↓
Difference Array
     ↓
Mark boundaries
     ↓
Prefix Sum
     ↓
Final Array
```

---

# 9. Important Trick to Remember

For:

```text
[l, r] += x
```

remember:

```text
       START          END
          ↓            ↓
diff[l] += x      diff[r+1] -= x
```

The `+x` starts the effect.

The `-x` stops the effect **after ****`r`**.

---

# 10. Difference Array vs Prefix Sum

| Technique        | Main Purpose          |
| ---------------- | --------------------- |
| Prefix Sum       | Fast range **query**  |
| Difference Array | Fast range **update** |

### Prefix Sum

```text
Many queries → Fast range sum
```

### Difference Array

```text
Many updates → Fast range modification
```

A useful way to remember:

```text
Prefix Sum       → Query optimization
Difference Array → Update optimization
```

---

# 11. Common Mistake

For:

```text
[l, r] += x
```

Don't write:

```cpp
diff[r] -= x;     // WRONG
```

Use:

```cpp
diff[r + 1] -= x; // CORRECT
```

Because the effect must continue **through index ****`r`** and stop from `r+1`.

---

# 12. One-Line Revision

> **Difference Array converts range updates from updating every element to updating only two boundaries, and a prefix sum reconstructs the final array.**

```text
[l,r] += x
    ↓
diff[l] += x
diff[r+1] -= x
    ↓
Prefix Sum
    ↓
Final Array
```

# Binary Lifting
(i) Why 2's power??
    Every number can be represented in 2's power
(ii) Must knows this formula
=> 2^j = 2*(2^j-1) = 2^j-1+2^j-1
So, use it parent[parent[node][j-1]][j-1]
(iii) Rows = node, col = logN base 2 + 1s , N = no of nodes 
(iv)  Always put values columnwise
(v) To find kth anchestor
    int getKthAncestor(int node, int k) {
        for(int j = 0; j < LOG; j++){
            if(k & (1 << j)){
                node = anchestor[node][j];
                if(node == -1) return -1;
            }
        }
        return node;
    }
# LC-1658,3254etc, which have to remove prefix and suffix
These are finding the maximum subarray
# How to find non overlapping arrays
