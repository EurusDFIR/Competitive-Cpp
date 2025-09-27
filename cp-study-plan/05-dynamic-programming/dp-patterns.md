# Dynamic Programming (DP)

## Khái niệm cơ bản

**Dynamic Programming**: Kỹ thuật giải quyết bài toán bằng cách chia nhỏ thành các subproblems, lưu kết quả để tránh tính toán lại.

### Điều kiện để dùng DP:
1. **Optimal Substructure**: Lời giải tối ưu có thể xây dựng từ lời giải tối ưu của subproblems
2. **Overlapping Subproblems**: Các subproblems được tính toán nhiều lần

## 1. Fibonacci - Ví dụ cơ bản

### Recursive (Inefficient - O(2^n))
```cpp
int fibRecursive(int n) {
    if (n <= 1) return n;
    return fibRecursive(n-1) + fibRecursive(n-2);
}
```

### Memoization - Top Down (O(n))
```cpp
vector<int> memo(n+1, -1);

int fibMemo(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    
    memo[n] = fibMemo(n-1) + fibMemo(n-2);
    return memo[n];
}
```

### Tabulation - Bottom Up (O(n))
```cpp
int fibDP(int n) {
    if (n <= 1) return n;
    
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n];
}
```

### Space Optimized (O(1))
```cpp
int fibOptimized(int n) {
    if (n <= 1) return n;
    
    int prev2 = 0, prev1 = 1;
    for (int i = 2; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}
```

## 2. Knapsack Problems

### 0/1 Knapsack
**Problem**: Có n items, mỗi item có weight[i] và value[i]. Tìm max value với weight tổng ≤ W.

```cpp
int knapsack01(vector<int>& weights, vector<int>& values, int W) {
    int n = weights.size();
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i-1] <= w) {
                dp[i][w] = max(dp[i-1][w], 
                              dp[i-1][w-weights[i-1]] + values[i-1]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    
    return dp[n][W];
}
```

### Space Optimized 0/1 Knapsack
```cpp
int knapsackOptimized(vector<int>& weights, vector<int>& values, int W) {
    vector<int> dp(W+1, 0);
    
    for (int i = 0; i < weights.size(); i++) {
        for (int w = W; w >= weights[i]; w--) {  // Reverse để tránh dùng lại
            dp[w] = max(dp[w], dp[w-weights[i]] + values[i]);
        }
    }
    
    return dp[W];
}
```

### Unbounded Knapsack
**Problem**: Có thể dùng mỗi item nhiều lần.

```cpp
int unboundedKnapsack(vector<int>& weights, vector<int>& values, int W) {
    vector<int> dp(W+1, 0);
    
    for (int w = 1; w <= W; w++) {
        for (int i = 0; i < weights.size(); i++) {
            if (weights[i] <= w) {
                dp[w] = max(dp[w], dp[w-weights[i]] + values[i]);
            }
        }
    }
    
    return dp[W];
}
```

## 3. Longest Common Subsequence (LCS)

**Problem**: Tìm độ dài subsequence chung dài nhất của 2 strings.

```cpp
int lcs(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[m][n];
}
```

### LCS với path reconstruction
```cpp
string getLCS(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    
    // Build DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    // Reconstruct LCS
    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i-1] == s2[j-1]) {
            lcs = s1[i-1] + lcs;
            i--; j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    
    return lcs;
}
```

## 4. Longest Increasing Subsequence (LIS)

### O(n²) Solution
```cpp
int lis(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    return *max_element(dp.begin(), dp.end());
}
```

### O(n log n) Solution với Binary Search
```cpp
int lisOptimal(vector<int>& arr) {
    vector<int> temp;
    
    for (int x : arr) {
        auto it = lower_bound(temp.begin(), temp.end(), x);
        if (it == temp.end()) {
            temp.push_back(x);
        } else {
            *it = x;
        }
    }
    
    return temp.size();
}
```

## 5. Coin Change Problems

### Coin Change - Minimum coins
**Problem**: Tìm số coin ít nhất để tạo amount.

```cpp
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);  // Initialize với giá trị lớn
    dp[0] = 0;
    
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    
    return dp[amount] > amount ? -1 : dp[amount];
}
```

### Coin Change - Number of ways
**Problem**: Đếm số cách tạo amount.

```cpp
int coinChangeWays(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    
    for (int coin : coins) {
        for (int i = coin; i <= amount; i++) {
            dp[i] += dp[i - coin];
        }
    }
    
    return dp[amount];
}
```

## 6. DP trên Grid/Matrix

### Unique Paths (Robot in grid)
```cpp
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));
    
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    
    return dp[m-1][n-1];
}
```

### Minimum Path Sum
```cpp
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    
    dp[0][0] = grid[0][0];
    
    // First row
    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }
    
    // First column  
    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }
    
    // Fill rest
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }
    
    return dp[m-1][n-1];
}
```

## Common DP Patterns

### 1. Linear DP
- Fibonacci, Climbing Stairs
- House Robber
- Maximum Subarray (Kadane's Algorithm)

### 2. Grid DP
- Unique Paths, Minimum Path Sum
- Triangle Path Sum
- Cherry Pickup

### 3. String DP
- LCS, LIS
- Edit Distance
- Palindrome problems

### 4. Knapsack variants
- 0/1 Knapsack, Unbounded Knapsack
- Subset Sum, Partition Equal Subset Sum
- Coin Change

### 5. Tree DP
- Maximum path sum in tree
- Diameter of tree
- House Robber in tree

## Bài tập thực hành

### Easy
1. Climbing Stairs
2. House Robber  
3. Maximum Subarray

### Medium
4. Coin Change
5. Longest Common Subsequence
6. 0/1 Knapsack

### Hard
7. Edit Distance
8. Longest Increasing Subsequence
9. Maximum Rectangle in Binary Matrix

## Tips quan trọng

1. **Identify state**: dp[i] đại diện cho gì?
2. **Find recurrence relation**: dp[i] relate với các state trước đó như thế nào?
3. **Base cases**: Khởi tạo các giá trị đầu
4. **Order of computation**: Bottom-up hay top-down?
5. **Space optimization**: Có thể giảm space complexity không?