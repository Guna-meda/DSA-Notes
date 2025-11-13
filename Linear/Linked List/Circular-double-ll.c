#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *llink , *rlink;
} NODE;

void insert_front(NODE *ptr , int ele) {
    NODE *temp = malloc(sizeof(NODE));
    temp-> data = ele;
    NODE *first = ptr -> rlink;
    ptr->rlink = temp;
    temp->llink = ptr;
    temp->rlink = first;
    first->llink = temp;
}

void insert_rear(NODE *ptr , int ele){
    NODE *temp = malloc(sizeof(NODE));
    temp-> data = ele;
    NODE *last = ptr -> llink;
    last->rlink = temp;
    temp->llink = last;
    temp->rlink = ptr;
    ptr->llink = temp;
}

void display(NODE *ptr) {
    if (ptr->rlink == ptr) {  
        printf("List is empty\n");
        return;
    }

    NODE *current = ptr->rlink;
    printf("List elements: ");
    while (current != ptr) {
        printf("%d <-> ", current->data);
        current = current->rlink;
    }

    printf("(back to head)\n"); 
}

void delete_front (NODE *ptr) {
    if(ptr->rlink == ptr) {
        printf("List is empty\n");
        return;
    }
    NODE *first = ptr -> rlink;
    int x = first->data;
    ptr->rlink = first->rlink;
    first->rlink->llink = ptr;
    free(first);
    printf("Deleted element from front: %d\n", x);
}

void delete_rear (NODE *ptr) {
    if(ptr->llink == ptr) {
        printf("List is empty\n");
        return;
    }
    NODE *last = ptr -> llink;
    int x = last->data;
    ptr->llink = last->llink;
    last->llink->rlink = ptr;
    free(last);
    printf("Deleted element from rear: %d\n", x);
}

void free_list(NODE *ptr) {
    if (ptr->rlink == ptr) {
        printf("List is empty\n");
        return;
    }

    NODE *cur = ptr->rlink;
    NODE *next;
    while (cur != ptr) {
        next = cur->rlink;
        free(cur);
        cur = next;
    }
    free(ptr);
}

int main() {
    NODE *head = malloc(sizeof(NODE));
    head->llink = head;
    head->rlink = head;

    while (1)
    {
        printf("1. Insert at front\n");
        printf("2. Insert at rear\n");
        printf("3. Delete from front\n");
        printf("4. Delete from rear\n");
        printf("5. Display list\n");
        printf("6. Free list\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Insert at front
                insert_front(head, 10); // Example value
                break;
            case 2:
                // Insert at rear
                insert_rear(head, 20); // Example value
                break;
            case 3:
                // Delete from front
                delete_front(head); 
                break;
            case 4:
                // Delete from rear
                delete_rear(head);
                break;
            case 5:
                // Display list
                display(head);
                break;
            case 6:
                free_list(head);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    
}