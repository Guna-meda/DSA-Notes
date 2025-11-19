#include<stdio.h>
#define MAX 10

int adjMatrix[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = 0, rear = 0;

void enqueue(int vertex) {
    queue[rear++] = vertex;
}

int dequeue() {
    return queue[front++];
}

int isQueueEmpty() {
    return front == rear;
}

void bfs(int startVertex, int numVertices) {
    enqueue(startVertex);
    visited[startVertex] = 1;

    while(!isQueueEmpty()) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);

        for(int i = 0; i < numVertices; i++) {
            if(adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int numVertices, numEdges, from, to, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    // Initialize adjacency matrix and visited array
    for (int i = 1; i <= numVertices; i++) {
        for (int j = 1; j <= numVertices; j++) {
            adjMatrix[i][j] = 0;
        }
        visited[i] = 0;
    }

    // Input edges
    for (int i = 0; i < numEdges; i++) {
        printf("Enter edge (from to): ");
        scanf("%d %d", &from, &to);
        adjMatrix[from][to] = 1;  // For directed graph
        adjMatrix[to][from] = 1; // For undirected graph (comment this line for directed graph)
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    printf("BFS traversal: ");
    bfs(startVertex, numVertices);

    return 0;
}