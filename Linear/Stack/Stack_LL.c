#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} NODE;

typedef struct stack
{
    NODE *top;
} STACK;

STACK *createStack()
{
    STACK *stack = (STACK *)malloc(sizeof(STACK));
    stack->top = NULL;
    return stack;
}

int isEmpty(STACK *stack)
{
    return stack->top == NULL;
}

int isFull(STACK *stack)
{
    return 0; // Linked list implementation is never full
}

void init_stack(STACK *ptr)
{
    ptr->top = NULL;
}

void push(STACK *stack, int item)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if (!newNode)
    {
        printf("Heap overflow\n");
        return;
    } // A heap overflow occurs when the program tries to allocate memory on the heap
    //(using malloc or similar), but the system cannot provide more memory—usually
    // because the heap is full or the system is out of memory.

    newNode->data = item;
    if (stack->top == NULL)
    {
        stack->top = newNode;
        newNode->link = NULL;
        return;
    }

    newNode->link = stack->top;
    stack->top = newNode;
}

void pop(STACK *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow\n");
        return;
    }
    NODE *temp = stack->top;
    stack->top = stack->top->link;
    printf("Popped element is %d\n", temp->data);
    free(temp);
}

int peek(STACK *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->top->data;
}

void display(STACK *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return;
    }
    NODE *current = stack->top;
    printf("Stack elements: ");
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->link;
    }
    printf("NULL\n");
}

// Function to free all nodes in the stack
void destroyStack(STACK *stack)
{
   NODE *prev = NULL;
   NODE *cur = stack->top;
    while (cur != NULL)
    {
         prev = cur;
         cur = cur->link;
         free(prev);
    }
}

// Or we can use free(stack) if we are sure that all nodes are already popped

// void destroyStack(STACK *stack) {
//     while (!isEmpty(stack)) {
//         pop(stack);
//     }
//     free(stack);
// }

int main()
{
    int choice, value;
    STACK *stack = createStack();
    init_stack(stack);

    while (1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Check if empty\n");
        printf("5. Check if full\n");
        printf("6. Exit\n");
        printf("7. Display stack\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(stack, value);
            break;
        case 2:
            pop(stack);
            break;
        case 3:
            value = peek(stack);
            if (value != -1)
            {
                printf("Top value: %d\n", value);
            }
            break;
        case 4:
            if (isEmpty(stack))
            {
                printf("Stack is empty\n");
            }
            else
            {
                printf("Stack is not empty\n");
            }
            break;
        case 5:
            if (isFull(stack))
            {
                printf("Stack is full\n");
            }
            else
            {
                printf("Stack is not full\n");
            }
            break;
        case 6:
            destroyStack(stack);
            free(stack);
            exit(0);
        case 7:
            display(stack);
            break;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}