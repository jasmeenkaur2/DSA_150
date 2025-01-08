# Why Does `unordered_map` Use Less Space Than a Generic Hash Map?

Although `unordered_map` in C++ uses a **hash map** internally, its implementation is optimized to use less space compared to generic hash maps. Here's why:

## 1. **Efficient Buckets**
- `unordered_map` uses **buckets** to group elements with the same hash value.
- Each bucket directly stores key-value pairs, minimizing extra memory usage.
- Generic hash maps may use **linked lists** or **trees** in buckets, which require extra pointers or metadata.

## 2. **Dynamic Memory Allocation**
- `unordered_map` allocates memory **only when needed**, keeping unused space low.
- Generic hash maps might pre-allocate large arrays or use less efficient memory management, wasting space.

## 3. **Collision Management**
- `unordered_map` resolves hash collisions efficiently with minimal overhead.
- Generic hash maps may use longer chains or larger structures (like trees) for handling collisions, consuming more memory.

## 4. **Compact Node Design**
- Nodes in `unordered_map` only store the key, value, and a small pointer for chaining if needed.
- Generic hash maps might add extra fields for bookkeeping, increasing memory usage.

## 5. **Load Factor Control**
- `unordered_map` adjusts the size of its bucket array dynamically, ensuring efficient use of memory.
- Generic hash maps might use less optimized resizing strategies, wasting memory.

### Summary
The **optimized design** of `unordered_map` (e.g., compact buckets, efficient memory allocation, and smart collision handling) makes it more memory-efficient than many generic hash map implementations.
