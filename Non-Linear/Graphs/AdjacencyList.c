#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct node {
    int data;
    struct node *next;
};

void createAdjacencyList(struct node *adjList) {
    int numVertices , from , to;
    struct node *newNode, *temp;
    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);

    // store number of vertices in the first node
    adjList[0].data = numVertices;
    adjList[0].next = NULL;

    // Initialize adjacency list for each vertex
    for(int i = 1; i <= numVertices; i++) {
        adjList[i].data = i;
        adjList[i].next = NULL;
    }

    printf("Enter edges (from to). Enter 0 0 to stop:\n");
    while(1) {
        scanf("%d %d", &from, &to);
        if(from == 0 && to == 0) {
            break;
        }
        if(from> 0 && from<= numVertices && to> 0 && to<= numVertices) {
            temp = &adjList[from];

            // Traverse to the end of the linked list for the vertex 'from'
            while(temp->next != NULL) {
                temp = temp->next;
            }
            // Create a new node for the vertex 'to' and add it to the list
            newNode = (struct node*)malloc(sizeof(struct node));
            newNode->data = to;
            newNode->next = NULL;
            temp->next = newNode;
        } else {
            printf("Invalid edge! Please enter valid vertices.\n");
        }
        
    }
}

void displayAdjacencyList(struct node *adjList) {
    struct node *temp;

    for(int i = 1; i <= adjList[0].data; i++) {
        printf("Vertex %d:", adjList[i].data);
        temp = adjList[i].next;
        while(temp != NULL) {
            printf(" -> %d", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct node adjList[MAX];  // Array of nodes to represent the adjacency list
    
    createAdjList(adjList);  // Create the adjacency list
    displayAdjList(adjList); // Display the adjacency list
    
    return 0;
}