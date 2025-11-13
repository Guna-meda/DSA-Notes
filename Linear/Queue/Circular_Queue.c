// use f=(f + 1)%size insted of f+1 and r=(r + 1)%size instead of r+1
// queue has only one element when f==r
// queue is empty when f==-1

#include <stdio.h>
# define MAX 10

void enqueue(int q[], int *f, int *r, int ele) {
    if (*f == 0 && *r == MAX - 1 || *f == *r + 1) {
        printf("Overflow\n");
    } else {
        if (*f == -1) { // Queue is empty
            *f = 0;
        }
        *r = (*r + 1) % MAX;
        q[*r] = ele;
    }
}

void dequeue(int q[], int *f, int *r) {
    int x;
    if (*f == -1) { // Queue is empty
        printf("Underflow\n");
    } else {
        x = q[*f];
        if (*f == *r) { // Queue has only one element
            *f = -1;
            *r = -1;
        } else {
            *f = (*f + 1) % MAX;
        }
        printf("Deleted element is %d\n", x);
    }
}

void display(int q[], int f, int r) {
    if (f == -1) { // Queue is empty
        printf("Queue is empty\n");
    } else {
        int i = f;
        while (1) {
            printf("%d ", q[i]);
            if (i == r) {
                break;
            }
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

int main() {
    int q[MAX], f = -1, r = -1, x, ele, ch;
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    do {
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the element to be inserted : ");
                scanf("%d", &ele);
                enqueue(q, &f, &r, ele);
                break;
            case 2:
                dequeue(q, &f, &r);
                break;
            case 3:
                display(q, f, r);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (ch != 4);
}
