# Purpose of \( k \% n \) in LeetCode 61 (Rotate List)

The purpose of using \( k \% n \) in **LeetCode 61 (Rotate List)** is to optimize the number of rotations when \( k \) (the number of rotations) is larger than \( n \) (the length of the linked list).

---

## Why \( k \% n \) is Important

Rotating a linked list \( n \) times results in the same list because the entire list effectively "wraps around." For example:

- For a list `1 -> 2 -> 3 -> 4 -> 5`:
  - Rotating 5 times results in `1 -> 2 -> 3 -> 4 -> 5` (the original list).
  - Rotating 6 times is equivalent to rotating 1 time: `5 -> 1 -> 2 -> 3 -> 4`.

Thus, performing \( k \% n \) reduces unnecessary rotations and ensures you only rotate the list the minimum number of times needed to achieve the desired result.

---

## Key Insights
1. **If \( k < n \)**: \( k \% n = k \), so the number of rotations remains \( k \).
2. **If \( k \geq n \)**: \( k \% n \) gives the remainder when \( k \) is divided by \( n \), which represents the "effective rotations."

For example:
- If \( n = 5 \) and \( k = 12 \):
  - \( k \% n = 12 \% 5 = 2 \), so performing 12 rotations is the same as performing 2 rotations.

---

## How It Works in Code
```cpp
k %= n; // Reduce k to the effective number of rotations
if (k == 0) return head; // If no rotations are needed, return the original list
