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

void bfs(int adj[MAX][MAX], int visited[MAX], int n, int start) {
    front = rear = -1; // reset queue for each component

    enqueue(start);
    visited[start] = 1;

    while (front <= rear) {
        int node = dequeue();
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
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
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    int components = 0;

    printf("\nConnected Components:\n");

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            components++;
            printf("Component %d: ", components);
            bfs(adj, visited, n, i);
            printf("\n");
        }
    }

    printf("\nTotal number of components = %d\n", components);

    return 0;
}