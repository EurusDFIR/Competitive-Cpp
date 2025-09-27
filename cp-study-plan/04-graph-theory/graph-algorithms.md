# Graph Theory - Lý thuyết đồ thị

## 1. Biểu diễn Graph

### Adjacency List (Khuyến khích)
```cpp
// Undirected graph
vector<vector<int>> graph(n);  // n vertices
for (int i = 0; i < m; i++) {  // m edges
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);  // Undirected
}

// Directed graph  
vector<vector<int>> graph(n);
for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);  // Only u -> v
}

// Weighted graph
vector<vector<pair<int,int>>> graph(n);  // {neighbor, weight}
for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
    graph[v].push_back({u, w}); // If undirected
}
```

### Adjacency Matrix (Khi n nhỏ ≤ 1000)
```cpp
vector<vector<int>> adj(n, vector<int>(n, 0));
for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u][v] = 1;
    adj[v][u] = 1;  // If undirected
}
```

## 2. Breadth-First Search (BFS)

### Template cơ bản
```cpp
vector<int> bfs(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> result;
    queue<int> q;
    
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        result.push_back(current);
        
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    
    return result;
}
```

### BFS tìm shortest path (unweighted)
```cpp
vector<int> shortestPath(vector<vector<int>>& graph, int start, int end) {
    int n = graph.size();
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);
    queue<int> q;
    
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        if (current == end) break;
        
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = current;
                q.push(neighbor);
            }
        }
    }
    
    // Reconstruct path
    vector<int> path;
    int curr = end;
    while (curr != -1) {
        path.push_back(curr);
        curr = parent[curr];
    }
    reverse(path.begin(), path.end());
    
    return path;
}
```

## 3. Depth-First Search (DFS)

### Template cơ bản (Recursive)
```cpp
void dfs(vector<vector<int>>& graph, int node, vector<bool>& visited, vector<int>& result) {
    visited[node] = true;
    result.push_back(node);
    
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(graph, neighbor, visited, result);
        }
    }
}

vector<int> dfsTraversal(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> result;
    
    dfs(graph, start, visited, result);
    return result;
}
```

### DFS Iterative (dùng Stack)
```cpp
vector<int> dfsIterative(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> result;
    stack<int> s;
    
    s.push(start);
    
    while (!s.empty()) {
        int current = s.top();
        s.pop();
        
        if (!visited[current]) {
            visited[current] = true;
            result.push_back(current);
            
            // Add neighbors in reverse order để maintain order
            for (int i = graph[current].size() - 1; i >= 0; i--) {
                int neighbor = graph[current][i];
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }
    
    return result;
}
```

## 4. Dijkstra Algorithm (Shortest Path - Weighted)

### Implementation với Priority Queue
```cpp
vector<int> dijkstra(vector<vector<pair<int,int>>>& graph, int start) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    // pair: {distance, node}
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (d > dist[u]) continue;  // Already processed
        
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}
```

### Dijkstra với path reconstruction
```cpp
pair<vector<int>, vector<int>> dijkstraWithPath(vector<vector<pair<int,int>>>& graph, int start) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    
    return {dist, parent};
}

vector<int> getPath(vector<int>& parent, int start, int end) {
    vector<int> path;
    int curr = end;
    while (curr != -1) {
        path.push_back(curr);
        curr = parent[curr];
    }
    reverse(path.begin(), path.end());
    return path;
}
```

## 5. Floyd-Warshall Algorithm (All-pairs shortest path)

```cpp
void floydWarshall(vector<vector<int>>& dist) {
    int n = dist.size();
    
    // dist[i][j] = weight of edge i->j, hoặc INF nếu không có edge
    // dist[i][i] = 0
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

// Usage example
int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> dist(n, vector<int>(n, INF));
    
    // Initialize diagonal
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }
    
    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
        // dist[v][u] = w;  // If undirected
    }
    
    floydWarshall(dist);
    
    // dist[i][j] now contains shortest path from i to j
    return 0;
}
```

## Time Complexity Summary

| Algorithm | Time Complexity | Space Complexity | Use Case |
|-----------|----------------|------------------|----------|
| BFS | O(V + E) | O(V) | Unweighted shortest path, Level traversal |
| DFS | O(V + E) | O(V) | Connectivity, Cycle detection, Topological sort |
| Dijkstra | O((V + E) log V) | O(V) | Single-source shortest path (non-negative weights) |
| Floyd-Warshall | O(V³) | O(V²) | All-pairs shortest path |

## Bài tập thực hành

### Easy
1. BFS/DFS traversal
2. Check if graph is connected
3. Find shortest path in unweighted graph

### Medium
4. Dijkstra shortest path
5. Detect cycle in undirected graph
6. Count connected components

### Hard
7. All-pairs shortest path
8. Find bridges in graph
9. Strongly connected components

## Tips quan trọng

1. **Adjacency List vs Matrix**: List tốt cho sparse graphs, Matrix tốt cho dense graphs
2. **BFS cho shortest path** trong unweighted graph
3. **Dijkstra không work** với negative weights
4. **Floyd-Warshall** dùng khi cần all-pairs shortest paths
5. **Always check bounds** khi access graph vertices