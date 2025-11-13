// Implementation of a Circular Queue using Linked List
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* link;
} NODE;

void enqueue(NODE **front, NODE **rear, int ele) {
    NODE *temp = malloc(sizeof(NODE));
    temp->data = ele;
    if(*front == NULL) { // Queue is empty
        *front = *rear = temp;
        temp->link = temp; // Point to itself
    } else {
        temp->link = (*rear)->link; // New node points to front
        (*rear)->link = temp; // Old rear points to new node
        *rear = temp; // Update rear to new node
    }
}

void display(NODE *front, NODE *rear) {
    if(front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    NODE *cur = front;
    do {
        printf("%d ", cur->data);
        cur = cur->link;
    } while(cur != front);
    printf("\n");
}

void dequeue(NODE **front, NODE **rear) {
    if(*front == NULL) { // Queue is empty
        printf("Underflow\n");
        return;
    }
    int x = (*front)->data;
    if(*front == *rear) { // Only one element
        free(*front);
        *front = *rear = NULL;
    } else {
        NODE *temp = *front;
        *front = (*front)->link;
        (*rear)->link = *front; // Update rear's link to new front
        free(temp);
    }
    printf("Deleted element is %d\n", x);
}

int main() {
    NODE *front = NULL, *rear = NULL;
    int x, ele, ch;
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    do {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch) {    
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &ele);
                enqueue(&front, &rear, ele);
                break;
            case 2:
                dequeue(&front, &rear);
                break;
            case 3:
                display(front, rear);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }

    } while(ch != 4);
    return 0;
}