#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

void bfs(int adj[MAX][MAX], int visited[MAX], int n, int start) {
    enqueue(start);
    visited[start] = 1;

    printf("BFS traversal: ");
    while (front <= rear) {
        int node = dequeue();
        if (node == -1) break;
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

int main() {
    int n;
    int adj[MAX][MAX];
    int visited[MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%d x %d) row by row (use 0/1 values):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &adj[i][j]) != 1) {
                fprintf(stderr, "Insufficient or invalid input while reading adjacency matrix\n");
                return 1;
            }
        }
    }

    // Start BFS from vertex 0
    bfs(adj, visited, n, 0);

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