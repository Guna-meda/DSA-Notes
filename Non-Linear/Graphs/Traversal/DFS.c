#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10

struct Node {
    int adjacentNode;
    struct Node *next;
};

void initializeGraph(struct Node *adjList[]);
void createGraph(struct Node *adjList[], int nodeCount);
void initializeVisited(int visited[], int nodeCount);
void depthFirstSearch(struct Node *adjList[], int startNode, int visited[]);
void insertAtEnd(struct Node *adjList[], int sourceNode, int destinationNode);
void displayGraph(struct Node *adjList[], int nodeCount);

int main() {
    struct Node *adjList[MAX_NODES];
    int visited[MAX_NODES];
    int nodeCount, startNode;

    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &nodeCount);

    initializeGraph(adjList);
    createGraph(adjList, nodeCount);

    printf("\nGraph representation:\n");
    displayGraph(adjList, nodeCount);

    initializeVisited(visited, nodeCount);

    printf("\nEnter the starting node for DFS: ");
    scanf("%d", &startNode);
    printf("\nDFS Traversal: ");
    depthFirstSearch(adjList, startNode, visited);

    return 0;
}

void initializeGraph(struct Node *adjList[]) {
    for (int i = 1; i <= MAX_NODES; i++) {
        adjList[i] = NULL;
    }
}

void createGraph(struct Node *adjList[], int nodeCount) {
    int sourceNode, destinationNode;
    while (1) {
        printf("Enter edge (source destination) or 0 0 to stop: ");
        scanf("%d %d", &sourceNode, &destinationNode);
        if (sourceNode == 0 && destinationNode == 0) {
            break;
        }
        insertAtEnd(adjList, sourceNode, destinationNode);
    }
}

void initializeVisited(int visited[], int nodeCount) {
    for (int i = 1; i <= nodeCount; i++) {
        visited[i] = 0;
    }
}

void depthFirstSearch(struct Node *adjList[], int startNode, int visited[]) {
    struct Node *current;
    visited[startNode] = 1;
    printf(" %d", startNode);

    current = adjList[startNode];
    while (current != NULL) {
        if (!visited[current->adjacentNode]) {
            depthFirstSearch(adjList, current->adjacentNode, visited);
        }
        current = current->next;
    }
}

void insertAtEnd(struct Node *adjList[], int sourceNode, int destinationNode) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *current;

    newNode->adjacentNode = destinationNode;
    newNode->next = NULL;

    if (adjList[sourceNode] == NULL) {
        adjList[sourceNode] = newNode;
    } else {
        current = adjList[sourceNode];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void displayGraph(struct Node *adjList[], int nodeCount) {
    struct Node *current;
    for (int i = 1; i <= nodeCount; i++) {
        printf("\nNodes adjacent to %d:", i);
        current = adjList[i];
        while (current != NULL) {
            printf(" %d ->", current->adjacentNode);
            current = current->next;
        }
        printf(" NULL");
    }
    printf("\n");
}
