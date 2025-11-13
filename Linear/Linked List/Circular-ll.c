#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} NODE;

typedef struct list {
    NODE *head;
} LIST;

//the same thing , without using LIST structure we can do by taking NODE *ptr in functions and insted of ptr->head we can use ptr

void insert_front(LIST *ptr , int ele) {
    NODE *temp = malloc(sizeof(NODE));
    temp-> data = ele;
    NODE *first = ptr -> head -> link;
    ptr->head->link = temp;
    temp->link = first;
}

void insert_rear(LIST *ptr , int ele){
    NODE *temp = malloc(sizeof(NODE));
    temp-> data = ele;
    temp->link = ptr -> head;
    NODE *cur = ptr -> head;
    while (cur->link != ptr->head) {
        cur = cur->link;
    }
    cur->link = temp;
}

void display(LIST *ptr) {
    if (ptr->head == NULL) {  
        printf("List is empty\n");
        return;
    }

    NODE *current = ptr->head;
    printf("List elements: ");
    do {
        printf("%d -> ", current->data);
        current = current->link;
    } while (current != ptr->head);

    printf("(back to head)\n"); 
}

void delete_front (LIST *ptr) {
    if(ptr->head->link == ptr->head) {
        printf("List is empty\n");
        return;
    }
    NODE *first = ptr -> head -> link;
    int x = first->data;
    ptr->head->link = first->link;
    free(first);
    printf("Deleted element from front: %d\n", x);
}

void delete_end (LIST *ptr) {
    if(ptr->head->link == ptr->head) {
        printf("List is empty\n");
        return;
    }
    NODE *cur = ptr -> head;
    NODE *prev = NULL;
    while(cur->link != ptr->head) {
        prev = cur;
        cur = cur->link;
    }
    prev->link = cur->link;
    free(cur);
    printf("Deleted element from end: %d\n", cur->data);
}

void free_list(LIST *ptr) {
    if (ptr->head->link == ptr->head) {
        printf("List is empty\n");
        return;
    }

    NODE *cur = ptr->head->link;
    NODE *next;
    while (cur != ptr->head) {
        next = cur->link;
        free(cur);
        cur = next;
    }
    free(ptr->head);
    free(ptr);
}

void search(LIST *ptr , int x) {
    if(ptr->head->link == ptr->head) {
        printf("List is empty\n");
        return;
    }
    NODE *cur = ptr -> head -> link;
    int pos = 0;
    while(cur != ptr->head) {
        if(cur->data == x) {
            printf("Element %d found at position %d\n", x, pos);
            return;
        }
        cur = cur -> link;
        pos++;
    }
    printf("Element %d not found in the list\n", x);
}

void sort(LIST *ptr) {
    if(ptr->head->link == ptr->head) {
        printf("List is empty\n");
        return;
    }
    NODE *i, *j;
    int temp;
    for(i = ptr->head->link; i->link != ptr->head; i = i->link) {
        for(j = i->link; j != ptr->head; j = j->link) {
            if(i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted\n");
}



int main() {
    LIST *list = malloc(sizeof(LIST));
    list->head = NULL;

    int choice, value, position;

    while (1) {
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from position\n");
        printf("7. Display list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insert_front(list, value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insert_end(list, value);
                break;
            case 3:
                printf("Enter value and position to insert: ");
                scanf("%d %d", &value, &position);
                insert_pos(list, value, position);
                break;
            case 4:
                delete_front(list);
                break;
            case 5:
                delete_end(list);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                delete_pos(list, position);
                break;
            case 7:
                display(list);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}