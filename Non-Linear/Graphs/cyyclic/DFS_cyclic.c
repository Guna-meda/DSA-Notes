#include <stdio.h>

#define MAX 100

int visited[MAX];

int dfsCycle(int adj[MAX][MAX], int n, int node, int parent) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1) {

            // If not visited → go deeper
            if (!visited[i]) {
                if (dfsCycle(adj, n, i, node))
                    return 1;
            }

            // If visited & not parent → cycle!
            else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;   // No cycle here
}

int main() {
    int n, adj[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    // Initialize visited array
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int cycle = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfsCycle(adj, n, i, -1)) {
                cycle = 1;
                break;
            }
        }
    }

    if (cycle)
        printf("Graph has a CYCLE.\n");
    else
        printf("Graph has NO cycle.\n");

    return 0;
}