// Implementation of a Doubly Ended Queue
// queue full condition : (front == 0 && rear == MAX-1) || (front == rear + 1)
// display from front to rear

#include <stdio.h>
#define MAX 10

void input_front(int *q , int *f, int *r, int ele){
    if((*f == 0 && *r == MAX-1) || (*f == *r + 1)){
        printf("Queue is full\n");
        return;
    }
    if(*f == -1){
        *f = *r = 0;
    } else if(*f == 0){
        *f = MAX - 1;
    } else {
        (*f)--;// this is when front is in middle
    }
    q[*f] = ele;
}

void input_rear(int *q , int *f, int *r, int ele){
    if((*f == 0 && *r == MAX-1) || (*f == *r + 1)){
        printf("Queue is full\n");
        return;
    }
    if(*f == *r == -1){
        *f = *r = 0;
    } else if(*r == MAX - 1){
        *r = 0;
    } else {
        (*r)++;// this is when rear is in middle
    }
    q[*r] = ele;
}

void delete_front(int *q , int *f, int *r){
    if(*f == -1){
        printf("Queue is empty\n");
        return;
    }
    int x = q[*f];
    if(*f == *r){// only one element
        *f = *r = -1;
    } else if(*f == MAX - 1){
        *f = 0;
    } else {
        (*f)++;
    }
    printf("Deleted element is %d\n", x);
}

void delete_rear(int *q , int *f, int *r){
    if(*f == -1){
        printf("Queue is empty\n");
        return;
    }
    int x = q[*r];
    if(*f == *r){// only one element
        *f = *r = -1;
    } else if(*r == 0){
        *r = MAX - 1;
    } else {
        (*r)--;
    }
    printf("Deleted element is %d\n", x);
}

void display(int *q , int f, int r){
    if(f == -1){
        printf("Queue is empty\n");
        return;
    }
    int i = f;
    while(1){
        printf("%d ", q[i]);
        if(i == r){
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    int q[MAX], f = -1, r = -1, x, ele, ch;
    printf("1. Enqueue at rear\n2. Enqueue at front\n3. Dequeue from front\n4. Dequeue from rear\n5. Display\n6. Exit\n");
    do {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: printf("Enter element to insert: ");
                    scanf("%d", &ele);
                    input_rear(q, &f, &r, ele);
                    break;
            case 2: printf("Enter element to insert: ");
                    scanf("%d", &ele);
                    input_front(q, &f, &r, ele);
                    break;
            case 3: delete_front(q, &f, &r);
                    break;
            case 4: delete_rear(q, &f, &r);
                    break;
            case 5: display(q, f, r);
                    break;
            case 6: printf("Exiting...\n");
                    break;
            default: printf("Invalid choice\n");
        }
    } while(ch != 6);
    return 0;
}