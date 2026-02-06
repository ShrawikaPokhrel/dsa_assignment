# Dijkstra’s Algorithm Implementation in C
# 1. Introduction
This program implements **Dijkstra's algorithm** to find the shortest path from a source vertex to all other vertices in a weighted graph.

# 2. Data Structure Definition
 Graph Representation:
- The graph is represented using a **2D adjacency matrix**.
- `graph[i][j]` holds the weight of the edge between vertex `i` and vertex `j`.
- A value of `0` indicates no direct edge between nodes.

 Other Arrays:
- `dist[]` stores the shortest distance from the source node to every other node.
- `visited[]` keeps track of vertices whose minimum distance from the source is finalized.

# 3. Function Descriptions

-> `minDistance(int dist[], int visited[], int vertices)`
- Finds the vertex with the minimum distance value from the set of vertices not yet processed.
- Returns the index of this vertex.

->`dijkstra(int graph[MAX][MAX], int vertices, int src, int dist[])`
- Implements Dijkstra’s algorithm.
- Initializes distances and visited arrays.
- Repeatedly selects the nearest unvisited vertex, then updates the distances of adjacent vertices.
- `dist[]` is updated with the shortest distances from the source.

-> `printDistances(int dist[], int vertices, int src)`
- Prints the shortest distances from the source to all vertices.
- Shows `INF` if a vertex is not reachable from the source.

# 4. Overview of `main()` Function
1. Defines a sample weighted graph using an adjacency matrix.
2. Specifies the number of vertices and the source vertex.
3. Calls `dijkstra()` to compute shortest paths.
4. Calls `printDistances()` to display results.

# 5. Sample Output

Vertex Distance from Source 0
0 0
1 7
2 9
3 11
4 20
5 20