// Implementation of a Simple Queue using Linked List

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* link;
} NODE;

void enqueue(NODE **front, NODE **rear, int ele) {
    NODE *temp = malloc(sizeof(NODE));
    temp->data = ele;
    temp->link = NULL;
    if(*rear == NULL) {
        *front = *rear = temp;
    } else {
        (*rear)->link = temp;
        *rear = temp;
    }
}

void display(NODE *front) {
    if(front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    NODE *cur = front;
    while(cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->link;
    }
    printf("\n");
}

void dequeue(NODE **front, NODE **rear) {
    if(*front == NULL) {
        printf("Underflow\n");
        return -1;
    }
    int x = (*front)->data;
    NODE *temp = *front;
    *front = (*front)->link;
    if(*front == NULL) {
        *rear = NULL;
    }
    free(temp);
    printf("Deleted element is %d\n", x);
}

int main () {
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
                display(front);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(ch != 4);
    return 0;
}