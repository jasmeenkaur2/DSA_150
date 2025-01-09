### **How Bit Manipulation Works for Counting Bits in C++**

We use **bitwise operations** to count the number of `1`s in the binary representation of a number. The process involves repeatedly checking the least significant bit (LSB) and shifting the number to the right until it becomes `0`.

---

### **Steps to Count Bits Using Bit Manipulation**

1. **Start with the number in binary form.**
2. **Check the LSB using `n & 1`:**
   - This operation checks if the rightmost bit is `1`.
3. **Add the result of `n & 1` to the count.**
4. **Right-shift the number using `n >>= 1`:**
   - This moves all bits one position to the right, discarding the LSB.
5. Repeat steps 2-4 until the number becomes `0`.

---

### **Example: Counting Bits in `5`**

Let’s take the number `5` (binary: `101`) as an example.

| Step | Binary (`n`) | Decimal (`n`) | `n & 1` (Check LSB) | Add to `count` | `n >>= 1` (Shift Right) |
|------|--------------|---------------|---------------------|----------------|-------------------------|
| 1    | `101`        | 5             | 1                   | `count = 1`    | `010` (2 in decimal)    |
| 2    | `010`        | 2             | 0                   | `count = 1`    | `001` (1 in decimal)    |
| 3    | `001`        | 1             | 1                   | `count = 2`    | `000` (0 in decimal)    |
| 4    | `000`        | 0             | -                   | Stop           | -                       |

**Final Count:** `2` ones in the binary representation of `5`.

---

### **Code Implementation**

```cpp
#include <iostream>
using namespace std;

int countBits(int n) {
    int count = 0;
    while (n > 0) {           // Loop until the number becomes 0
        count += n & 1;       // Add 1 to count if LSB is 1
        n >>= 1;              // Right-shift the number by 1
    }
    return count;             // Return the total count of 1s
}

int main() {
    int num = 5;
    cout << "Number of 1s in binary of " << num << ": " << countBits(num) << endl;
    return 0;
}
```

---

### **Key Bitwise Operations**
1. **`n & 1`:**  
   Checks if the LSB is `1`. Example:  
   - `101 & 001 = 001 (1)`
   - `010 & 001 = 000 (0)`

2. **`n >>= 1`:**  
   Shifts bits to the right. Example:  
   - `101 (binary for 5)` → `010 (binary for 2)`  
   - `010` → `001 (binary for 1)`

---

### **Why Use Bit Manipulation?**
- It’s **efficient** because it directly works on binary representations.
- Time complexity: **O(log(n))**, where `n` is the number of bits in the number.
- Space complexity: **O(1)** (only a few variables are used).