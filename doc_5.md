# Documentation: Program 5 – Implement undirected Graph Using Adjacency Matrix with BFS and DFS

# 1. Objective
The objective of this program is to implement an **undirected graph** using an **adjacency matrix** and to traverse the graph using **Breadth First Search (BFS)** and **Depth First Search (DFS)** techniques. This program demonstrates how graph traversal algorithms work on an undirected graph.

# 2. Graph Representation
2.1 Undirected Graph
An undirected graph is a graph in which the edges have no direction. If there is an edge between vertex `u` and vertex `v`, then both vertices are considered adjacent to each other.

2.2 Adjacency Matrix
The adjacency matrix is a two-dimensional array used to represent a graph.  
- If an edge exists between vertex `i` and vertex `j`, the value is `1`.  
- Otherwise, the value is `0`.

For an undirected graph:
adj[i][j] = adj[j][i] = 1
# 3. Data Structures Used
- Adjacency Matrix: A 2D array to store the graph.
- Visited Array: Used to keep track of visited vertices.
- Queue: Used in BFS traversal.
- Recursion: Used in DFS traversal.

# 4. Functions Implemented
4.1 `void BFS(int start)`
- Traverses the graph using Breadth First Search.
- Uses a queue to visit vertices level by level.
- Marks vertices as visited to avoid revisiting.
- Prints the traversal order starting from the given vertex.

# 4.2 `void DFS(int start)`
- Traverses the graph using Depth First Search.
- Uses recursion to explore each vertex deeply.
- Marks vertices as visited to avoid repetition.
- Prints the traversal order starting from the given vertex.

# 5. Working of Algorithms
 5.1 Breadth First Search (BFS)
1. Start from the given vertex.
2. Mark it as visited and insert it into the queue.
3. Remove a vertex from the queue and visit all its adjacent unvisited vertices.
4. Repeat until the queue becomes empty.

 5.2 Depth First Search (DFS)
1. Start from the given vertex.
2. Mark it as visited.
3. Visit an unvisited adjacent vertex recursively.
4. Backtrack when no adjacent unvisited vertex is found.

# 6.Example 
Vertices - 0 1 2 3
Edges
 0 – 1
0 – 2
1 – 3
2 – 3
Adjacency Matrix:
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0
# 7. Sample Output

- BFS Traversal (Starting from vertex 0)
0 1 2 3

-DFS Traversal (Starting from vertex 0)
0 1 3 2