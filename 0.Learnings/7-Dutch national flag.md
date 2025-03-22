# Dutch National Flag Algorithm (DNFA) - Complete Notes (C++ ISA)

## 📌 Introduction
The **Dutch National Flag Algorithm (DNFA)** is an efficient **three-way partitioning** algorithm used for sorting arrays containing exactly **three distinct elements**. It is widely used in **sorting problems, partitioning tasks, and optimizing Quick Sort**.

### **Why is it called "Dutch National Flag"?**
It is named after the **Dutch flag**, which has three colors (`Red, White, and Blue`). The algorithm partitions elements into **three groups** similar to these colors.

---
## 🚀 **How DNFA Works?**
DNFA uses a **three-pointer approach**:
1. **low** → Marks the boundary for the first group (values smaller than pivot).
2. **mid** → Traverses the array (current element being checked).
3. **high** → Marks the boundary for the last group (values greater than pivot).

### **Algorithm Steps**
1️⃣ Initialize three pointers:
   - `low = 0`, `mid = 0`, `high = n - 1`
   
2️⃣ **Process the array** while `mid <= high`:
   - **If `arr[mid] == 0`** → Swap `arr[mid]` with `arr[low]`, then increment `low` and `mid`.
   - **If `arr[mid] == 1`** → Leave it as is and increment `mid`.
   - **If `arr[mid] == 2`** → Swap `arr[mid]` with `arr[high]`, then decrement `high`.

3️⃣ **End condition**: When `mid > high`, the array is sorted.

---
## 📌 **C++ Code Implementation**
```cpp
#include <iostream>
using namespace std;

void sortColors(int arr[], int n) {
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[mid], arr[low]);
            low++; mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else { // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {2, 0, 2, 1, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    sortColors(arr, n);
    printArray(arr, n);
    return 0;
}
```

---
## 📊 **Time & Space Complexity**
| Complexity | Value | Explanation |
|------------|--------|-------------|
| **Time Complexity** | **O(n)** | Each element is processed only once. |
| **Space Complexity** | **O(1)** | Works **in-place**, no extra memory needed. |

---
## 📌 **Use Cases of DNFA**
DNFA is optimal when dealing with **three distinct elements** and requires efficient partitioning.

### **Common Problems Where DNFA is Best**
1️⃣ **LeetCode 75: Sort Colors** (Sorting `0s, 1s, and 2s`).
2️⃣ **Segregating Even and Odd Numbers** (Placing evens before odds).
3️⃣ **Segregating Positive and Negative Numbers** (Moving negatives to the left).
4️⃣ **Partitioning Around a Pivot** (Used in Quick Sort 3-way partitioning).
5️⃣ **Sorting RGB Balls** (Grouping `Red, Green, Blue`).

---
## ❌ **When NOT to Use DNFA**
- If the number of distinct elements is **more than three**, DNFA is **not optimal**.
- If **full general sorting is required**, use **Quick Sort, Merge Sort, or Counting Sort** instead.
- If **stable sorting is required** with more than three elements.

---
## 🎯 **Key Takeaways**
✅ **Best for three-way partitioning problems (like `0,1,2` sorting).**  
✅ **Faster than Quick Sort for three distinct elements (`O(n) vs. O(n log n)`).**  
✅ **Works in-place (O(1) space).**  
✅ **Three-pointer approach makes it efficient and easy to implement.**  

💡 **If a problem involves exactly three unique values, DNFA is the best and fastest choice!** 🚀

