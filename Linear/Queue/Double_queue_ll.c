// Implementation of a Double-Ended Queue using Linked List

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* rlink;
    struct Node* llink;
} NODE; 

void input_front(NODE **front, NODE **rear, int ele) {
    NODE *temp = malloc(sizeof(NODE));
    temp->data = ele;
    temp->llink = NULL;
    temp->rlink = NULL;
    if(*front == NULL) { // Queue is empty
        *front = *rear = temp;
    } else {
        temp->rlink = *front;
        (*front)->llink = temp;
        *front = temp;
    }
}

void input_rear(NODE **front, NODE **rear, int ele) {
    NODE *temp = malloc(sizeof(NODE));
    temp->data = ele;
    temp->llink = NULL;
    temp->rlink = NULL;
    if(*rear == NULL) { // Queue is empty
        *front = *rear = temp;
    } else {
        temp->llink = *rear;
        (*rear)->rlink = temp;
        *rear = temp;
    }
}

void delete_front(NODE **front, NODE **rear) {
    if(*front == NULL) { // Queue is empty
        printf("Underflow\n");
        return;
    }
    int x = (*front)->data;
    NODE *temp = *front;
    *front = (*front)->rlink;
    if(*front != NULL) {
        (*front)->llink = NULL;
    } else {
        *rear = NULL; // Queue is now empty
    }
    free(temp);
    printf("Deleted element is %d\n", x);
}

void delete_rear(NODE **front, NODE **rear) {
    if(*rear == NULL) { // Queue is empty
        printf("Underflow\n");
        return;
    }
    int x = (*rear)->data;
    NODE *temp = *rear;
    *rear = (*rear)->llink;
    if(*rear != NULL) {
        (*rear)->rlink = NULL;
    } else {
        *front = NULL; // Queue is now empty
    }
    free(temp);
    printf("Deleted element is %d\n", x);
}

void display(NODE *front, NODE *rear) {
    if(front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    NODE *cur = front;
    printf("Queue elements: ");
    while(cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->rlink;
    }
    printf("\n");
}

int main() {
    NODE *front = NULL, *rear = NULL;
    int x, ele, ch;
    printf("1. Enqueue at rear\n2. Enqueue at front\n3. Dequeue from front\n4. Dequeue from rear\n5. Display\n6. Exit\n");
    do {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Enter element to enqueue at rear: ");
                scanf("%d", &ele);
                input_rear(&front, &rear, ele);
                break;
            case 2:
                printf("Enter element to enqueue at front: ");
                scanf("%d", &ele);
                input_front(&front, &rear, ele);
                break;
            case 3:
                delete_front(&front, &rear);
                break;
            case 4:
                delete_rear(&front, &rear);
                break;
            case 5:
                display(front, rear);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }   
    } while(ch != 6);
    return 0;
}