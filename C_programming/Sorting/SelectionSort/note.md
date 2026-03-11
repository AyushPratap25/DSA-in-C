When an array is passed to a function, it becomes a pointer → sizeof(arr) gives pointer size (4/8 bytes), not array size.

✅ Correct way: calculate size in main.