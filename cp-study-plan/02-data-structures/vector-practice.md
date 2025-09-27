# 20 Bài tập Vector - Easy đến Medium

## 🟢 EASY LEVEL (Bài 1-8)

### Bài 1: Vector Basic Operations
**Đề bài**: Thực hiện các thao tác cơ bản trên vector: thêm phần tử, xóa phần tử cuối, in size và tất cả elements.

**Input**:
```
6
1 10
1 20  
1 30
2
3
4
```
*Lệnh: 1 x (thêm x), 2 (xóa cuối), 3 (in size), 4 (in tất cả)*

**Output**:
```
2
10 20
```

**Hint**: Dùng `push_back()`, `pop_back()`, `size()`. Luôn check `!empty()` trước khi `pop_back()`.

---

### Bài 2: Array to Vector Conversion
**Đề bài**: Đọc mảng, chuyển thành vector, sắp xếp và in ra.

**Input**:
```
5
3 1 4 1 5
```

**Output**:
```
1 1 3 4 5
```

**Hint**: Khởi tạo vector với size, dùng `sort(v.begin(), v.end())`. Tránh push_back trong loop nếu biết trước size.

---

### Bài 3: Vector Sum and Average
**Đề bài**: Tính tổng và trung bình cộng của vector.

**Input**:
```
4
10 20 30 40
```

**Output**:
```
Sum: 100
Average: 25.00
```

**Hint**: Dùng range-based for loop `for(int x : v)` để tính tổng. Cast sang double cho average.

---

### Bài 4: Find Min Max
**Đề bài**: Tìm giá trị nhỏ nhất, lớn nhất và vị trí của chúng trong vector.

**Input**:
```
6
5 2 8 1 9 3
```

**Output**:
```
Min: 1 at index 3
Max: 9 at index 4
```

**Hint**: Dùng `min_element(v.begin(), v.end())` và `max_element()`. Trừ `v.begin()` để lấy index.

---

### Bài 5: Vector Reverse
**Đề bài**: Đảo ngược vector và in ra.

**Input**:
```
5
1 2 3 4 5
```

**Output**:
```
5 4 3 2 1
```

**Hint**: Dùng `reverse(v.begin(), v.end())` hoặc duyệt ngược với `for(int i = v.size()-1; i >= 0; i--)`.

---

### Bài 6: Count Occurrences
**Đề bài**: Đếm số lần xuất hiện của một giá trị trong vector.

**Input**:
```
7 3
1 3 2 3 1 3 2
```

**Output**:
```
3
```

**Hint**: Dùng `count(v.begin(), v.end(), target)` hoặc loop với counter.

---

### Bài 7: Remove Duplicates
**Đề bài**: Xóa các phần tử trùng lặp trong vector đã sắp xếp.

**Input**:
```
8
1 1 2 2 2 3 3 4
```

**Output**:
```
1 2 3 4
```

**Hint**: Sau khi sort, dùng `unique(v.begin(), v.end())` rồi `resize()`. Hoặc dùng two-pointers technique.

---

### Bài 8: Vector Insert and Erase
**Đề bài**: Chèn phần tử vào vị trí và xóa phần tử tại vị trí cho trước.

**Input**:
```
5
1 2 3 4 5
2 99
1
```
*Insert 99 at index 2, then erase at index 1*

**Output**:
```
1 3 99 4 5
```

**Hint**: Dùng `insert(v.begin() + pos, value)` và `erase(v.begin() + pos)`. Chú ý insert/erase là O(n).

---

## 🟡 MEDIUM LEVEL (Bài 9-20)

### Bài 9: Subarray Maximum Sum
**Đề bài**: Tìm tổng lớn nhất của subarray liên tiếp (Kadane's Algorithm).

**Input**:
```
9
-2 1 -3 4 -1 2 1 -5 4
```

**Output**:
```
6
```

**Hint**: Dùng Kadane's algorithm với two variables: `current_sum` và `max_sum`. Reset current_sum về 0 nếu âm.

---

### Bài 10: Rotate Array
**Đề bài**: Xoay vector sang phải k vị trí.

**Input**:
```
7 3
1 2 3 4 5 6 7
```

**Output**:
```
5 6 7 1 2 3 4
```

**Hint**: Dùng `reverse()` 3 lần: reverse toàn bộ, reverse [0, k-1], reverse [k, n-1]. Hoặc dùng `rotate()`.

---

### Bài 11: Merge Two Sorted Vectors
**Đề bài**: Merge hai vector đã sắp xếp thành một vector sắp xếp.

**Input**:
```
4 5
1 3 5 7
2 4 6 8 9
```

**Output**:
```
1 2 3 4 5 6 7 8 9
```

**Hint**: Dùng two pointers technique. Hoặc copy vào một vector rồi `sort()`, nhưng two pointers hiệu quả hơn.

---

### Bài 12: Binary Search in Vector
**Đề bài**: Tìm vị trí của target trong sorted vector (hoặc -1 nếu không tìm thấy).

**Input**:
```
6 5
1 2 4 5 7 9
```

**Output**:
```
3
```

**Hint**: Dùng `binary_search()` để check exist, `lower_bound()` để tìm vị trí. Hoặc implement custom binary search.

---

### Bài 13: Next Permutation
**Đề bài**: Tìm permutation kế tiếp theo thứ tự lexicographical.

**Input**:
```
3
1 2 3
```

**Output**:
```
1 3 2
```

**Hint**: Dùng `next_permutation(v.begin(), v.end())`. Trả về false nếu đã là permutation cuối.

---

### Bài 14: Sliding Window Maximum
**Đề bài**: Tìm maximum trong mỗi window size k khi slide qua vector.

**Input**:
```
8 3
1 3 -1 -3 5 3 6 7
```

**Output**:
```
3 3 5 5 6 7
```

**Hint**: Dùng deque để maintain decreasing order trong window. Hoặc dùng multiset cho approach đơn giản hơn.

---

### Bài 15: Longest Increasing Subsequence Length
**Đề bài**: Tìm độ dài của subsequence tăng dần dài nhất.

**Input**:
```
8
10 9 2 5 3 7 101 18
```

**Output**:
```
4
```

**Hint**: Dùng DP với vector `dp[i]` = length of LIS ending at i. Hoặc optimize với binary search + vector.

---

### Bài 16: Two Sum
**Đề bài**: Tìm hai phần tử có tổng bằng target, return indices.

**Input**:
```
4 9
2 7 11 15
```

**Output**:
```
0 1
```

**Hint**: Sort với pair {value, index}, dùng two pointers. Hoặc dùng hash map nhưng đây là bài vector nên focus vào approach vector.

---

### Bài 17: Product Except Self
**Đề bài**: Với mỗi element, tính tích của tất cả elements khác (không dùng phép chia).

**Input**:
```
4
1 2 3 4
```

**Output**:
```
24 12 8 6
```

**Hint**: Dùng hai vector: `left[i]` = tích từ 0 đến i-1, `right[i]` = tích từ i+1 đến n-1. Optimize space bằng cách dùng output array.

---

### Bài 18: Container With Most Water
**Đề bài**: Tìm diện tích lớn nhất của container được tạo bởi hai đường thẳng.

**Input**:
```
9
1 8 6 2 5 4 8 3 7
```

**Output**:
```
49
```

**Hint**: Two pointers từ hai đầu. Di chuyển pointer có height nhỏ hơn vào trong. Area = min(height[left], height[right]) * (right - left).

---

### Bài 19: Stock Buy Sell
**Đề bài**: Tìm lợi nhuận tối đa từ một lần mua và một lần bán stock.

**Input**:
```
6
7 1 5 3 6 4
```

**Output**:
```
5
```

**Hint**: Track `min_price` và `max_profit` khi duyệt. Profit = current_price - min_price so far.

---

### Bài 20: Sort Colors (Dutch Flag)
**Đề bài**: Sắp xếp vector chỉ chứa 0, 1, 2 trong một lần duyệt.

**Input**:
```
6
2 0 2 1 1 0
```

**Output**:
```
0 0 1 1 2 2
```

**Hint**: Three pointers: `low` (boundary của 0), `mid` (current), `high` (boundary của 2). Swap elements để group theo colors.

---

## 📝 Vector Best Practices

### Performance Tips:
1. **Reserve memory**: `v.reserve(n)` khi biết trước size
2. **Avoid frequent reallocation**: Khởi tạo với size thay vì push_back nhiều lần
3. **Use iterators**: `v.begin()`, `v.end()` thay vì indices khi có thể
4. **Range-based loops**: `for(auto x : v)` cleaner và ít lỗi hơn

### Memory Management:
1. **Shrink capacity**: `v.shrink_to_fit()` sau khi xóa nhiều elements
2. **Clear vs assign**: `v.clear()` giữ capacity, `v = vector<int>()` reset capacity
3. **Avoid unnecessary copies**: Pass by reference `vector<int>&`

### Common Pitfalls:
1. **Index out of bounds**: Dùng `at()` để debug, `[]` để performance
2. **Iterator invalidation**: Insert/erase invalidate iterators
3. **Size vs capacity**: `size()` ≠ `capacity()`

**Happy Vector Coding! 🚀**