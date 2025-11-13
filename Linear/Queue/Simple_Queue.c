#include <stdio.h>
# define MAX 10

// initially , rear = -1 , front = 0  , we can also use front = -1
//underflow condition : front > rear and rear == -1 , if we take front = -1 then underflow condition : front == rear
//overflow condition : rear == size-1
// display from i=front to i=rear
// enqueue happens at rear end and dequeue happens at front end

void enqueue(int q[], int *r, int ele) {
    if (*r == MAX - 1) {
        printf("Overflow\n");
    } else {
        *r = *r + 1;
        q[*r] = ele;
    }
}

void dequeue(int q[], int *f, int *r) {
    int x;
    if (*f > *r || *r == -1) {
        printf("Underflow\n");
    } else {
        x = q[*f];
        *f = *f + 1;
        printf("Deleted element is %d\n", x);
    }
}   

void display(int q[], int f, int r) {
    if (f > r || r == -1) {
        printf("Queue is empty\n");
    } else {
        for (int i = f; i <= r; i++) {
            printf("%d ", q[i]);
        }
        printf("\n");
    }
}


int main () {
    int q[MAX], f = 0, r = -1, x, ele, ch;
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    do {
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                if (r == MAX - 1) {
                    printf("Overflow\n");
                } else {
                    printf("Enter the element to be inserted : ");
                    scanf("%d", &ele);
                    r++;
                    q[r] = ele;
                }
                break;
            case 2:
                if (f > r || r == -1) {
                    printf("Underflow\n");
                } else {
                    x = q[f];
                    f++;
                    printf("Deleted element is %d\n", x);
                }
                break;
            case 3:
                if (f > r || r == -1) {
                    printf("Queue is empty\n");
                } else {
                    for (int i = f; i <= r; i++) {
                        printf("%d ", q[i]);
                    }
                    printf("\n");
                }
                break;
            case 4:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (ch != 4);
}
