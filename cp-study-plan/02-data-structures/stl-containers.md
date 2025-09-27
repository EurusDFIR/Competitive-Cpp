# STL Containers - Data Structures

## 1. Vector (Dynamic Array)

### Khai báo và khởi tạo
```cpp
vector<int> v;                    // Vector rỗng
vector<int> v(10);               // 10 elements, giá trị 0
vector<int> v(10, 5);            // 10 elements, giá trị 5
vector<int> v = {1, 2, 3, 4};    // Khởi tạo với values
```

### Operations chính
```cpp
v.push_back(x);      // Thêm x vào cuối - O(1)
v.pop_back();        // Xóa element cuối - O(1)
v.size();            // Số elements - O(1)
v.empty();           // Kiểm tra rỗng - O(1)
v.clear();           // Xóa tất cả - O(n)
v[i];                // Access element thứ i - O(1)
v.front();           // Element đầu - O(1)
v.back();            // Element cuối - O(1)
```

### Duyệt Vector
```cpp
// Cách 1: Index
for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
}

// Cách 2: Iterator  
for (auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
}

// Cách 3: Range-based (C++11)
for (int x : v) {
    cout << x << " ";
}
```

## 2. Stack (LIFO - Last In First Out)

```cpp
stack<int> s;

s.push(x);           // Thêm x vào top - O(1)
s.pop();             // Xóa element top - O(1)  
s.top();             // Lấy element top - O(1)
s.empty();           // Kiểm tra rỗng - O(1)
s.size();            // Số elements - O(1)
```

### Ví dụ: Check balanced parentheses
```cpp
bool isBalanced(string s) {
    stack<char> st;
    
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            
            char top = st.top();
            st.pop();
            
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    
    return st.empty();
}
```

## 3. Queue (FIFO - First In First Out)

```cpp
queue<int> q;

q.push(x);           // Thêm x vào back - O(1)
q.pop();             // Xóa element front - O(1)
q.front();           // Lấy element front - O(1)
q.back();            // Lấy element back - O(1)
q.empty();           // Kiểm tra rỗng - O(1)
q.size();            // Số elements - O(1)
```

### Ví dụ: BFS implementation
```cpp
void bfs(vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        cout << current << " ";
        
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
```

## 4. Priority Queue (Heap)

### Max Heap (default)
```cpp
priority_queue<int> pq;          // Max heap

pq.push(x);          // Insert x - O(log n)
pq.pop();            // Remove max - O(log n)
pq.top();            // Get max - O(1)
pq.empty();          // Check empty - O(1)
pq.size();           // Get size - O(1)
```

### Min Heap
```cpp
priority_queue<int, vector<int>, greater<int>> pq;  // Min heap
// hoặc
priority_queue<int> pq;
// Lúc lấy ra: int x = -pq.top(); pq.pop(); (nếu push âm values)
```

### Custom comparator
```cpp
// Pair: sort theo first giảm dần, nếu bằng thì second tăng dần  
auto cmp = [](pair<int,int> a, pair<int,int> b) {
    if (a.first != b.first) return a.first < b.first;  // greater
    return a.second > b.second;  // less
};
priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
```

## 5. Set (Tập hợp có thứ tự)

```cpp
set<int> s;

s.insert(x);         // Thêm x - O(log n)
s.erase(x);          // Xóa x - O(log n)
s.count(x);          // Đếm x (0 hoặc 1) - O(log n)
s.find(x);           // Tìm x, return iterator - O(log n)
s.size();            // Số elements - O(1)
s.empty();           // Kiểm tra rỗng - O(1)
```

### Tìm kiếm nâng cao
```cpp
set<int> s = {1, 3, 5, 7, 9};

auto it = s.lower_bound(5);  // Iterator đến ≥ 5 (pointing to 5)
auto it2 = s.upper_bound(5); // Iterator đến > 5 (pointing to 7)

// Lấy element nhỏ nhất >= x
if (it != s.end()) {
    int val = *it;
}
```

## 6. Map (Key-Value pairs)

```cpp
map<string, int> mp;

mp[key] = value;     // Set/update - O(log n)
mp.count(key);       // Check exists - O(log n)
mp.find(key);        // Find key - O(log n)
mp.erase(key);       // Remove key - O(log n)
mp.size();           // Số pairs - O(1)
```

### Duyệt Map
```cpp
map<string, int> mp = {{"apple", 5}, {"banana", 3}};

for (auto& p : mp) {
    cout << p.first << ": " << p.second << endl;
}

// Hoặc
for (auto& [key, value] : mp) {  // C++17
    cout << key << ": " << value << endl;
}
```

## Unordered Containers (Hash-based)

### Khi nào dùng?
- Cần O(1) average time thay vì O(log n)
- Không cần thứ tự của elements
- **Lưu ý**: Worst case vẫn là O(n) khi hash collision nhiều

```cpp
unordered_set<int> us;       // Tương tự set nhưng O(1) average
unordered_map<string, int> um; // Tương tự map nhưng O(1) average
```

## Bài tập thực hành

### Easy
1. Implement stack using array
2. Check balanced parentheses  
3. Count frequency of elements using map

### Medium
4. Sliding window maximum using deque
5. LRU Cache implementation
6. Find k-th largest element using priority queue

## Tips quan trọng

1. **Vector vs Array**: Vector linh hoạt hơn, auto resize
2. **set vs unordered_set**: set có thứ tự, unordered_set nhanh hơn
3. **map vs unordered_map**: Tương tự như trên
4. **Priority queue default là max heap**
5. **Always check empty() trước khi pop/top**