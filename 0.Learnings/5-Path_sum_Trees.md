# Path Sum III - Explanation and Solution

## Problem Statement

Given the root of a binary tree and an integer `targetSum`, return the number of paths where the sum of the values along the path equals `targetSum`. The path does not need to start at the root or end at a leaf, but it must follow parent-child connections.

---

## Approach: Prefix Sum + DFS (Depth-First Search)

### **1️⃣ Understanding ****`prefixSum`**

- `prefixSum[x]` stores how many times the **prefix sum ****`x`**** has appeared** in the tree.
- When we visit a node, we:
  1. **Update ****`currentSum`** (sum of values from root to this node).
  2. **Check if ****`prefixSum[currentSum - targetSum]`**** exists**.
     - If yes, it means we found a valid path.
  3. **Add ****`currentSum`**** to ****`prefixSum`** (to track future paths).
  4. **Recur to left and right children**.
  5. **Remove ****`currentSum`**** from ****`prefixSum`**** (Backtracking Step)**.

---

## **2️⃣ Why Do We Remove ****`prefixSum[currentSum]`****?**

- **Each recursive call explores a different subtree**.
- **We don’t want sums from one path to interfere with another**.
- **Removing ****`currentSum`**** ensures that only valid paths in the current subtree are considered.**

---

## **3️⃣ Example Tree (with ****`targetSum = 8`****)**

```
       10
      /   \
     5    -3
    / \      \
   3   2      11
  / \    \
 3  -2    1
```

### **Step-by-Step Dry Run**

| Node        | `currentSum` | `prefixSum[currentSum]`    | Paths Found               |
| ----------- | ------------ | -------------------------- | ------------------------- |
| 10          | 10           | `{10:1}`                   | 0                         |
| 5           | 15           | `{10:1, 15:1}`             | 0                         |
| 3           | 18           | `{10:1, 15:1, 18:1}`       | ✅ 1 (path 10 → 5 → 3)     |
| 3           | 21           | `{10:1, 15:1, 18:1, 21:1}` | 0                         |
| (Backtrack) | Remove 21    | `{10:1, 15:1, 18:1}`       | -                         |
| -2          | 16           | `{10:1, 15:1, 18:1, 16:1}` | 0                         |
| (Backtrack) | Remove 16    | `{10:1, 15:1, 18:1}`       | -                         |
| (Backtrack) | Remove 18    | `{10:1, 15:1}`             | -                         |
| 2           | 17           | `{10:1, 15:1, 17:1}`       | 0                         |
| 1           | 18           | `{10:1, 15:1, 17:1, 18:1}` | ✅ 1 (path 10 → 5 → 2 → 1) |
| (Backtrack) | Remove 18    | `{10:1, 15:1, 17:1}`       | -                         |
| (Backtrack) | Remove 17    | `{10:1, 15:1}`             | -                         |
| (Backtrack) | Remove 15    | `{10:1}`                   | -                         |
| -3          | 7            | `{10:1, 7:1}`              | 0                         |
| 11          | 18           | `{10:1, 7:1, 18:1}`        | ✅ 1 (path 10 → -3 → 11)   |
| (Backtrack) | Remove 18    | `{10:1, 7:1}`              | -                         |
| (Backtrack) | Remove 7     | `{10:1}`                   | -                         |
| (Backtrack) | Remove 10    | `{}`                       | -                         |

### **Total Paths Found:** `3`

---

## **4️⃣ Final Code (With Backtracking)**

```cpp
#include <unordered_map>

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long, int> prefixSum;
        prefixSum[0] = 1;  // Base case: A sum of 0 exists once
        return dfs(root, 0, targetSum, prefixSum);
    }

private:
    int dfs(TreeNode* node, long currentSum, int targetSum, unordered_map<long, int>& prefixSum) {
        if (!node) return 0;

        currentSum += node->val;  // Update running sum

        int count = prefixSum[currentSum - targetSum]; // Check if any valid path exists

        prefixSum[currentSum]++; // Add current sum to the hash map

        // Recur to left and right children
        count += dfs(node->left, currentSum, targetSum, prefixSum);
        count += dfs(node->right, currentSum, targetSum, prefixSum);

        prefixSum[currentSum]--; // 🔥 Remove current sum (Backtrack)

        return count;
    }
};
```

---

## **5️⃣ Key Takeaways**

✅ `prefixSum[currentSum]` stores the **running sum count** at each node.\
✅ Before **leaving a node**, we **remove** its `currentSum` to prevent interference with **other branches**.\
✅ **Backtracking ensures** that each path is counted **only within its own subtree**, avoiding incorrect results.

🚀 **Think of it like "undoing" the last move before going back up the tree!**



