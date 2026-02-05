#include <stdio.h>
#include <stdlib.h>
#define MAX 100  
typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front > q->rear;
}

void enqueue(Queue* q, int value) {
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue* q) {
    int item = q->items[q->front];
    q->front++;
    return item;
}

typedef struct {
    int items[MAX];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

int isStackEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int value) {
    s->top++;
    s->items[s->top] = value;
}

int pop(Stack* s) {
    int item = s->items[s->top];
    s->top--;
    return item;
}

typedef struct {
    int vertices;           
    int adjMatrix[MAX][MAX]; 
} Graph;

void initGraph(Graph* g, int vertices) {
    g->vertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph* g, int v, int w) {
    if (v >= g->vertices || w >= g->vertices || v < 0 || w < 0) {
        printf("Error: Invalid vertices!\n");
        return;
    }
    g->adjMatrix[v][w] = 1;
    g->adjMatrix[w][v] = 1;
}

void displayMatrix(Graph* g) {
    printf("\nAdjacency Matrix:\n");
    printf("   ");

    for (int i = 0; i < g->vertices; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    
    for (int i = 0; i < g->vertices; i++) {
        printf("%2d [", i);
        for (int j = 0; j < g->vertices; j++) {
            printf("%2d", g->adjMatrix[i][j]);
            if (j < g->vertices - 1) printf(" ");
        }
        printf("]\n");
    }
}

void BFS(Graph* g, int startVertex) {
    if (startVertex >= g->vertices || startVertex < 0) {
        printf("Error: Invalid start vertex!\n");
        return;
    }
    
    int visited[MAX] = {0};
    Queue q;
    initQueue(&q);
    visited[startVertex] = 1;
    enqueue(&q, startVertex);
    printf("\nBFS Traversal starting from vertex %d:\n", startVertex);
    printf("Order: ");
    
    while (!isEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);
        
        for (int i = 0; i < g->vertices; i++) {
            if (g->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

void DFS(Graph* g, int startVertex) {
    if (startVertex >= g->vertices || startVertex < 0) {
        printf("Error: Invalid start vertex!\n");
        return;
    }
    
    int visited[MAX] = {0};
    Stack s;
    initStack(&s);

    push(&s, startVertex);
    
    printf("\nDFS Traversal starting from vertex %d:\n", startVertex);
    printf("Order: ");
 
    while (!isStackEmpty(&s)) {
        int currentVertex = pop(&s);
        if (visited[currentVertex]) {
            continue;
        }

        visited[currentVertex] = 1;
        printf("%d ", currentVertex);

        for (int i = g->vertices - 1; i >= 0; i--) {
            if (g->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                push(&s, i);
            }
        }
    }
    printf("\n");
}

int main() {
    Graph g;
    int vertices = 5; 
    
    printf("=== Undirected Graph Implementation ===\n");
    printf("Creating graph with %d vertices (0 to %d)\n", vertices, vertices-1);
    initGraph(&g, vertices);

    printf("\nAdding edges...\n");
    addEdge(&g, 0, 1);  // Edge between 0 and 1
    addEdge(&g, 0, 3);  // Edge between 0 and 3
    addEdge(&g, 1, 2);  // Edge between 1 and 2
    addEdge(&g, 1, 4);  // Edge between 1 and 4
    addEdge(&g, 2, 3);  // Edge between 2 and 3
    addEdge(&g, 2, 4);  // Edge between 2 and 4
    
    printf("Edges added: (0-1), (0-3), (1-2), (1-4), (2-3), (2-4)\n");

    displayMatrix(&g);
    BFS(&g, 0);
    DFS(&g, 0); 
    
    printf("\n--- Comparing BFS and DFS from different start vertices ---\n");
    
    BFS(&g, 2);
    DFS(&g, 2);
    
    printf("\n=== Program Complete ===\n");
    
    return 0;
}
