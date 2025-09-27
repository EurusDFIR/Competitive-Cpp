# Sorting Algorithms

## 1. STL Sort (Khuyến khích dùng)

### Cách dùng cơ bản
```cpp
#include <algorithm>
vector<int> arr = {3, 1, 4, 1, 5};
sort(arr.begin(), arr.end());  // Tăng dần
sort(arr.begin(), arr.end(), greater<int>());  // Giảm dần
```

### Sort với custom comparator
```cpp
// Sort pairs theo first tăng dần, nếu bằng thì second giảm dần
vector<pair<int,int>> pairs = {{1,3}, {2,1}, {1,2}};
sort(pairs.begin(), pairs.end(), [](pair<int,int> a, pair<int,int> b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second;
});
```

### Time Complexity: O(n log n)
### Space Complexity: O(log n) - recursive stack

## 2. Counting Sort

### Khi nào dùng?
- Các phần tử trong range nhỏ (≤ 10^6)
- Cần O(n) time complexity

```cpp
void countingSort(vector<int>& arr, int maxVal) {
    vector<int> count(maxVal + 1, 0);
    
    // Count occurrences
    for (int x : arr) {
        count[x]++;
    }
    
    // Rebuild array
    int idx = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i]-- > 0) {
            arr[idx++] = i;
        }
    }
}
```

### Time Complexity: O(n + k) where k = range
### Space Complexity: O(k)

# Binary Search

## 1. STL Binary Search

### Tìm vị trí
```cpp
vector<int> arr = {1, 2, 4, 4, 5, 6};
// arr PHẢI đã được sort!

// Tìm có tồn tại không
bool found = binary_search(arr.begin(), arr.end(), 4);

// Tìm vị trí đầu tiên >= x
auto it1 = lower_bound(arr.begin(), arr.end(), 4);
int pos1 = it1 - arr.begin();  // position 2

// Tìm vị trí đầu tiên > x  
auto it2 = upper_bound(arr.begin(), arr.end(), 4);
int pos2 = it2 - arr.begin();  // position 4
```

## 2. Custom Binary Search

### Template cơ bản
```cpp
// Tìm vị trí đầu tiên thỏa mãn condition
int binarySearch(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] >= target) {  // condition
            result = mid;
            right = mid - 1;  // tìm vị trí nhỏ hơn
        } else {
            left = mid + 1;
        }
    }
    
    return result;
}
```

### Binary Search trên Answer
```cpp
// Ví dụ: Tìm căn bậc 2 của n
double sqrt(double n) {
    double left = 0, right = n;
    double eps = 1e-9;
    
    while (right - left > eps) {
        double mid = (left + right) / 2;
        
        if (mid * mid <= n) {
            left = mid;
        } else {
            right = mid;
        }
    }
    
    return left;
}
```

## Bài tập thực hành

### Easy
1. Sort array of integers
2. Binary search in sorted array
3. Find first occurrence of element

### Medium  
4. Search in rotated sorted array
5. Find square root using binary search
6. Aggressive cows problem

### Time Complexity: O(log n)
### Space Complexity: O(1)

## Tips quan trọng

1. **Array phải sorted** trước khi binary search
2. **Avoid overflow**: dùng `mid = left + (right - left) / 2`
3. **Be careful with boundaries**: `<=` vs `<` trong while loop
4. **Test edge cases**: array rỗng, 1 element, target không tồn tại