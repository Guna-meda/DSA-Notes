//Using adjacency list:
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct node {
    int adjacentNode;
    struct node *next;
};

void initializeGraph(struct node *adjList[]) {
    for(int i = 0; i < MAX; i++) {
        adjList[i] = NULL;
    }
}

void createGraph(struct node *adjList[], int nodeCount) {
    int source, destination;

    while(1) {
        printf("Enter edge (source destination) or 0 0 to stop: ");
        scanf("%d %d", &source, &destination);
        if(source == 0 && destination == 0) {
            break;
        }
        insertAtEnd(adjList, source, destination);
    }
}

void insertAtEnd(struct node *adjList[], int source, int destination) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->adjacentNode = destination;
    newNode->next = NULL;

    if(adjList[source] == NULL) {
        adjList[source] = newNode;
    } else {
        struct node *temp = adjList[source];
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayGraph(struct node *adjList[], int nodeCount) {
    struct node *current;
    for (int i = 1; i <= nodeCount; i++) {
        printf("\nNodes adjacent to %d:", i);
        current = adjList[i];
        while (current != NULL) {
            printf(" -> %d", current->adjacentNode);
            current = current->next;
        }
        printf(" NULL");
    }
    printf("\n");
}

// BFS Implementation

void initializeVisited(int visited[], int nodeCount) {
    for(int i = 0; i <= nodeCount; i++) {
        visited[i] = 0;
    }
}

void breadthFirstSearch(struct node *adjList[], int startNode, int visited[]) {
    int queue[MAX], front = 0, rear = -1;
    struct node *current;

    visited[startNode] = 1;
    printf(" %d", startNode);
    queue[++rear] = startNode;

    while (front <= rear) {
        int currentNode = queue[front++];
        current = adjList[currentNode];

        while (current != NULL) {
            if (!visited[current->adjacentNode]) {
                visited[current->adjacentNode] = 1;
                printf(" %d", current->adjacentNode);
                queue[++rear] = current->adjacentNode;
            }
            current = current->next;
        }
    }
}

int main() {
    struct node *adjList[MAX];
    int visited[MAX];
    int nodeCount, startNode;

    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &nodeCount);

    initializeGraph(adjList);
    createGraph(adjList, nodeCount);

    printf("\nGraph representation:\n");
    displayGraph(adjList, nodeCount);

    initializeVisited(visited, nodeCount);

    printf("\nEnter the starting node for BFS: ");
    scanf("%d", &startNode);
    printf("\nBFS Traversal: ");
    breadthFirstSearch(adjList, startNode, visited);

    return 0;
}