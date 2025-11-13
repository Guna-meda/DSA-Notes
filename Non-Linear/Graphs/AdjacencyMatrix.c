#include <stdio.h>

#define MAX_VERTICES 10

// Add edge between src and dest
void addEdge(int graph[MAX_VERTICES][MAX_VERTICES], int src, int dest, int isDirected) {
    graph[src][dest] = 1;  // add edge src → dest

    if (!isDirected) {
        // For undirected graph, add both directions
        graph[dest][src] = 1;
    }
}

void display(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges;
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    int isDirected;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter 1 for Directed graph, 0 for Undirected: ");
    scanf("%d", &isDirected);

    printf("Enter edges (src dest):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest, isDirected);
    }

    display(graph, vertices);

    return 0;
}
