#include <stdio.h>

#define MAX 100

int visited[MAX];

void dfs(int adj[MAX][MAX], int n, int node) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(adj, n, i);
        }
    }
}

int main() {
    int n, adj[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int components = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(adj, n, i);   // explore this entire component
            components++;
        }
    }

    printf("Number of connected components = %d\n", components);

    return 0;
}