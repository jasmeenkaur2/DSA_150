

In C++, `umap` and `omap` usually refer to **unordered_map** and **ordered_map** (technically just `map`), respectively. They are part of the Standard Template Library (STL) and serve similar purposes but differ in their underlying implementations and behavior.

Here's a quick comparison:

| Feature                | **`unordered_map` (`umap`)**                  | **`map` (`omap`)**                            |
|------------------------|-----------------------------------------------|-----------------------------------------------|
| **Storage Order**      | Does **not** maintain any specific order.    | Maintains elements in **sorted order** based on the key. |
| **Underlying Structure** | Hash table                                 | Red-black tree (self-balancing binary tree)   |
| **Time Complexity**    | - Average: \( O(1) \) for insert, find, erase<br>- Worst-case: \( O(n) \) due to hash collisions | \( O(\log n) \) for insert, find, erase (always guaranteed) |
| **Key Type Requirements** | Requires a hash function and equality operator (`std::hash` by default). | Requires a comparison operator (default is `<`). |
| **Use Case**           | Faster access when order doesn't matter.     | When you need sorted keys or order-based operations. |
| **Insertion Order**    | No relation to insertion order or sorting.   | Automatically sorted by key.                 |

### When to Use Each

#### Use `unordered_map` (umap) when:
- You need **fast access** to elements by key.
- The order of elements **does not matter**.
- You want better average-case performance.

#### Use `map` (omap) when:
- You need **sorted keys**.
- You perform operations that benefit from **order**, like range queries.

### Example Code

#### Using `unordered_map`
```cpp
#include <unordered_map>
#include <iostream>

int main() {
    std::unordered_map<int, std::string> umap;
    umap[3] = "three";
    umap[1] = "one";
    umap[2] = "two";

    for (const auto& pair : umap) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }
    return 0;
}
```
**Output** (order may vary):
```
3: three
1: one
2: two
```

#### Using `map`
```cpp
#include <map>
#include <iostream>

int main() {
    std::map<int, std::string> omap;
    omap[3] = "three";
    omap[1] = "one";
    omap[2] = "two";

    for (const auto& pair : omap) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }
    return 0;
}
```
**Output** (always sorted):
```
1: one
2: two
3: three
``` 

### Summary
- Use `unordered_map` for speed.
- Use `map` when you need ordered keys.