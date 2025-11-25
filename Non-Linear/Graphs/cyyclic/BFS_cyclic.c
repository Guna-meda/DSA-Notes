#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int bfsCycle(int adj[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    int parent[MAX];

    for (int i = 0; i < n; i++)
        parent[i] = -1;

    enqueue(start);
    visited[start] = 1;

    while (front <= rear) {
        int node = dequeue();

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1) {
                
                if (!visited[i]) {
                    visited[i] = 1;
                    parent[i] = node;
                    enqueue(i);
                }

                else if (parent[node] != i) {
                    return 1;   // Cycle found
                }
            }
        }
    }

    return 0;  // No cycle
}

int main() {
    int n, adj[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    int cycle = 0;
    for (int i = 0; i < n; i++) {
        front = rear = -1;
        if (bfsCycle(adj, n, i)) {
            cycle = 1;
            break;
        }
    }

    if (cycle)
        printf("Graph has a CYCLE.\n");
    else
        printf("Graph has NO cycle.\n");

    return 0;
}