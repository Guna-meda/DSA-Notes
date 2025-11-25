#include <stdio.h>

#define MAX 100

void dfs(int adj[MAX][MAX], int visited[MAX], int n, int node) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1 && visited[i] == 0) {
            dfs(adj, visited, n, i);
        }
    }
}

int main() {
    int n;
    int adj[MAX][MAX];
    int visited[MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Start DFS from vertex 0
    dfs(adj, visited, n, 0);

    // Check if all vertices were visited
    int connected = 1;
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("\nGraph is CONNECTED.\n");
    else
        printf("\nGraph is NOT CONNECTED.\n");

    return 0;
}