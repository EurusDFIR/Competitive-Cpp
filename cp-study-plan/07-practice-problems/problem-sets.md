# Practice Problems - Bài tập thực hành

## 📚 Level 1: Beginner (Tuần 1 - Ngày 1-3)

### Data Structures
1. **Two Sum** (LeetCode 1)
   - **Tags**: Array, Hash Map
   - **Difficulty**: Easy
   - **Solution approach**: Dùng unordered_map để store visited elements

2. **Valid Parentheses** (LeetCode 20)
   - **Tags**: Stack, String
   - **Difficulty**: Easy  
   - **Solution approach**: Push opening brackets, pop và check khi closing

3. **Merge Two Sorted Lists** (LeetCode 21)
   - **Tags**: Linked List, Two Pointers
   - **Difficulty**: Easy

### Sorting & Searching
4. **Binary Search** (LeetCode 704)
   - **Tags**: Array, Binary Search
   - **Difficulty**: Easy
   - **Template**: Standard binary search

5. **First Bad Version** (LeetCode 278)
   - **Tags**: Binary Search
   - **Difficulty**: Easy
   - **Solution approach**: Binary search trên answer

6. **Search Insert Position** (LeetCode 35)
   - **Tags**: Array, Binary Search
   - **Difficulty**: Easy

## 🚀 Level 2: Intermediate (Tuần 1 - Ngày 4-6)

### Graph Theory
7. **Number of Islands** (LeetCode 200)
   - **Tags**: DFS, BFS, Graph
   - **Difficulty**: Medium
   - **Solution**: DFS/BFS để mark visited islands

8. **Course Schedule** (LeetCode 207)
   - **Tags**: DFS, BFS, Topological Sort
   - **Difficulty**: Medium
   - **Solution approach**: Detect cycle trong directed graph

9. **Shortest Path in Binary Matrix** (LeetCode 1091)
   - **Tags**: BFS, Matrix
   - **Difficulty**: Medium
   - **Solution**: BFS với 8 directions

### Dynamic Programming  
10. **Climbing Stairs** (LeetCode 70)
    - **Tags**: DP
    - **Difficulty**: Easy
    - **Recurrence**: dp[i] = dp[i-1] + dp[i-2]

11. **House Robber** (LeetCode 198)
    - **Tags**: DP
    - **Difficulty**: Medium
    - **Recurrence**: dp[i] = max(dp[i-1], dp[i-2] + nums[i])

12. **Coin Change** (LeetCode 322)
    - **Tags**: DP
    - **Difficulty**: Medium
    - **Pattern**: Unbounded knapsack

## 🏆 Level 3: Advanced (Tuần 2)

### Advanced DP
13. **Longest Common Subsequence** (LeetCode 1143)
    - **Tags**: DP, String
    - **Difficulty**: Medium
    - **2D DP**: dp[i][j] based on character match

14. **0/1 Knapsack** (Classic Problem)
    - **Tags**: DP
    - **Difficulty**: Medium
    - **Template**: 2D DP hoặc space-optimized 1D

15. **Longest Increasing Subsequence** (LeetCode 300)
    - **Tags**: DP, Binary Search
    - **Difficulty**: Medium
    - **Two approaches**: O(n²) DP, O(n log n) with binary search

### Graph Advanced
16. **Network Delay Time** (LeetCode 743)
    - **Tags**: Dijkstra, Graph
    - **Difficulty**: Medium
    - **Solution**: Single-source shortest path

17. **Cheapest Flights Within K Stops** (LeetCode 787)
    - **Tags**: DFS, BFS, Dijkstra
    - **Difficulty**: Medium
    - **Solution**: Modified Dijkstra hoặc Bellman-Ford

### Number Theory
18. **GCD of Strings** (LeetCode 1071)
    - **Tags**: String, Math
    - **Difficulty**: Easy
    - **Concept**: GCD với strings

19. **Pow(x, n)** (LeetCode 50)
    - **Tags**: Math, Binary Exponentiation
    - **Difficulty**: Medium
    - **Solution**: Fast exponentiation

20. **Count Primes** (LeetCode 204)
    - **Tags**: Math, Sieve
    - **Difficulty**: Medium
    - **Solution**: Sieve of Eratosthenes

---

## 🏃‍♂️ Contest Practice Problems

### Day 7 & 14: Mock Contest Problems

### Set A: Easy Contest (45-60 minutes)
1. **A + B Problem** - Basic I/O
2. **Array Sum** - Simple array operations  
3. **String Reverse** - Basic string manipulation
4. **Even/Odd Counter** - Simple counting

### Set B: Medium Contest (90-120 minutes)
1. **Maximum Subarray Sum** (Kadane's Algorithm)
2. **Binary Search on Answer** 
3. **BFS Shortest Path**
4. **Simple DP Problem**

### Set C: Advanced Contest (150+ minutes)
1. **Graph connectivity với DFS**
2. **DP với optimization**
3. **Number theory với modular arithmetic**
4. **Greedy algorithm**

---

## 📝 Solutions Template

### Problem Solution Format:
```cpp
/*
Problem: [Problem Name]
Tags: [Algorithm Tags]
Difficulty: [Easy/Medium/Hard]
Time Complexity: O(?)
Space Complexity: O(?)

Approach:
1. [Step 1 explanation]
2. [Step 2 explanation]
3. [Step 3 explanation]

Edge Cases:
- [Case 1]
- [Case 2]
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    fast_io;
    
    // Your solution here
    
    return 0;
}
```

---

## 🎯 Practice Schedule (2 weeks)

### Week 1: Foundation
- **Day 1-2**: Problems 1-6 (Data structures + Binary search)
- **Day 3-4**: Problems 7-9 (Graph basics)
- **Day 5-6**: Problems 10-12 (DP introduction)
- **Day 7**: Mock contest Set A + Set B

### Week 2: Advanced
- **Day 8-9**: Problems 13-15 (Advanced DP)
- **Day 10-11**: Problems 16-17 (Graph advanced) + 18-20 (Number theory)
- **Day 12-13**: Mixed practice + weak areas
- **Day 14**: Final mock contest Set C

---

## 💡 Study Tips

### Debugging Strategy:
1. **Read problem carefully** - Hiểu constraints và edge cases
2. **Start with brute force** - Tìm solution đơn giản trước
3. **Optimize step by step** - Improve time/space complexity
4. **Test với examples** - Verify với test cases cho sẵn
5. **Consider edge cases** - Empty input, single element, maximum values

### Time Management:
- **Easy problems**: 10-15 minutes
- **Medium problems**: 25-40 minutes  
- **Hard problems**: 45+ minutes
- **Leave time for debugging và testing**

### Contest Strategy:
1. **Read all problems first** (5-10 minutes)
2. **Solve easy problems first** để đảm bảo điểm
3. **Skip problems nếu stuck quá 30-40 minutes**
4. **Come back to skipped problems** nếu có thời gian
5. **Test thoroughly** trước khi submit

---

## 📚 Additional Resources

### Online Judges:
- **Codeforces**: contests + problemset
- **AtCoder**: beginner contests
- **LeetCode**: interview prep + contests
- **USACO**: structured learning path

### Books:
- "Competitive Programming" by Steven Halim
- "Algorithm Design Manual" by Steven Skiena
- "Introduction to Algorithms" (CLRS)

**Happy Coding! 🚀**