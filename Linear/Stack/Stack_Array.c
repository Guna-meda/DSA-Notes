#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Stack {
    int top;
    int a[MAX];
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->top++;
    stack->a[stack->top] = item;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    int x = stack->a[stack->top];
    stack->top--;
    return x;
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->a[stack->top];
}

void freeStack(Stack* stack) {
    free(stack);
}

void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->a[i]);
    }
    printf("\n");
}


int main() {
    Stack* stack = createStack();
    int choice, value;

    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Check if empty\n");
        printf("5. Check if full\n");
        printf("6. Exit\n");
        printf("7. Display stack\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(stack, value);
                break;
            case 2:
                value = pop(stack);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                value = peek(stack);
                if (value != -1) {
                    printf("Top value: %d\n", value);
                }
                break;
            case 4:
                if (isEmpty(stack)) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
            case 5:
                if (isFull(stack)) {
                    printf("Stack is full\n");
                } else {
                    printf("Stack is not full\n");
                }
                break;
            case 6:
                freeStack(stack);
                exit(0);
            case 7:
                printf("Stack elements: ");
                for (int i = 0; i <= stack->top; i++) {
                    printf("%d ", stack->a[i]);
                }
                printf("\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}