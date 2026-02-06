#include <stdio.h>
#include <limits.h>
#define MAX_VERTICES 100
#define INF_DISTANCE INT_MAX

int findMinDistVertex(int distances[], int visited[], int totalVerts) {
    int minDist = INF_DISTANCE;
    int minVertex = -1;

    for (int i = 0; i < totalVerts; i++) {
        if (visited[i] == 0 && distances[i] <= minDist) {
            minDist = distances[i];
            minVertex = i;
        }
    }
    return minVertex;
}

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int totalVerts, int src, int distances[]) {
    int visited[MAX_VERTICES];
    
    for (int i = 0; i < totalVerts; i++) {
        distances[i] = INF_DISTANCE;
        visited[i] = 0;  
    }

    distances[src] = 0;  
    for (int count = 0; count < totalVerts - 1; count++) {
        int u = findMinDistVertex(distances, visited, totalVerts);
        if (u == -1) break; 

        visited[u] = 1;

        for (int v = 0; v < totalVerts; v++) {
            if (!visited[v] && graph[u][v] != 0 && distances[u] != INF_DISTANCE &&
                distances[u] + graph[u][v] < distances[v]) {
                distances[v] = distances[u] + graph[u][v];
            }
        }
    }
}

void printDistances(int distances[], int totalVerts, int src) {
    printf("Vertex\tDistance from Source %d\n", src);
    for (int i = 0; i < totalVerts; i++) {
        if (distances[i] == INF_DISTANCE) {
            printf("%d\t\t%s\n", i, "INF");
        } else {
            printf("%d\t\t%d\n", i, distances[i]);
        }
    }
}

int main() {
    int totalVertices = 6;  
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};  

    graph[0][1] = 7;  graph[1][0] = 7;
    graph[0][2] = 9;  graph[2][0] = 9;
    graph[0][3] = 14; graph[3][0] = 14;
    graph[1][3] = 10; graph[3][1] = 10;
    graph[2][3] = 2;  graph[3][2] = 2;
    graph[2][4] = 11; graph[4][2] = 11;
    graph[3][5] = 9;  graph[5][3] = 9;
    graph[4][5] = 6;  graph[5][4] = 6;

    int dist[MAX_VERTICES];
    int startVertex = 0;  

    dijkstra(graph, totalVertices, startVertex, dist);
    printDistances(dist, totalVertices, startVertex);

    return 0;
}
