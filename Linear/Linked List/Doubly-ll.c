#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *rlink , *llink;
} NODE;

typedef struct list {
    NODE *head;
} LIST;

void insert_front(LIST *ptr , int ele) {
    NODE *temp = malloc(sizeof(NODE));
    temp->data = ele;
    temp->rlink = ptr -> head;
    temp->llink = NULL;
    if(ptr -> head != NULL) {
        ptr -> head -> llink = temp;
    }
    ptr -> head = temp; 
}

void insert_end(LIST *ptr , int ele){
    NODE *temp = malloc(sizeof(NODE));
    temp->data = ele;
    temp->rlink = NULL;
    temp->llink = NULL;
    if (ptr -> head == NULL) {
        ptr -> head = temp;
    } else {
        NODE *current = ptr -> head;
        while (current -> rlink != NULL) {
            current = current -> rlink;
        }
        current -> rlink = temp;
        temp -> llink = current;
    }
}

void insert_pos(LIST *ptr , int ele , int pos){
    NODE *temp = malloc(sizeof(NODE));
    temp->data = ele;
    temp->rlink = NULL;
    temp->llink = NULL;
    if (pos == 0) {
        temp->rlink = ptr -> head;
        if(ptr -> head != NULL) {
            ptr -> head -> llink = temp;
        }
        ptr -> head = temp;
    } else {
        NODE *current = ptr -> head;
        for (int i = 0; i < pos - 1 && current != NULL; i++) {
            current = current -> rlink;
        }
        if (current == NULL) {
            printf("Position out of bounds\n");
            free(temp);
        } else {
            temp->rlink = current -> rlink;
            temp->llink = current;
            if(current -> rlink != NULL) {
                current -> rlink -> llink = temp;
            }
        }
        current -> rlink = temp;
        temp -> llink = current;

    }
}

void delete_front(LIST *ptr){
    if(ptr->head == NULL) {
        printf("List is empty\n");
    } else {
        NODE *first = ptr -> head;
        ptr -> head = first -> rlink;
        if(ptr -> head != NULL) {
            ptr -> head -> llink = NULL;
        }
        printf("Deleted element is %d\n", first->data);
        free(first);
    }
}

void delete_end(LIST *ptr){
    if(ptr->head == NULL) {
        printf("List is empty\n");
    } else {
        if(ptr -> head -> rlink == NULL) {
            printf("Deleted element is %d\n", ptr -> head -> data);
            free(ptr -> head);
            ptr -> head = NULL;
        } else {
            NODE *current = ptr -> head;
            while(current -> rlink != NULL) {
                current = current -> rlink;
            }
            printf("Deleted element is %d\n", current -> data);
            free(current);
        }
    }
}

void display(LIST *ptr) {
    if (ptr->head == NULL) {
        printf("List is empty\n");
    } else {
        NODE *current = ptr->head;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->rlink;
        }
        printf("\n");
    }
}


int main () {
    int ch, ele , pos;
    LIST *start = malloc(sizeof(LIST));
    start -> head = NULL;
    printf("Enter your choice:\n1.Insert at beginning\n2.Insert at end\n3.Insert at position\n4.Delete from beginning\n5.Delete from end\n6.Display\n7.Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: {
                printf("Enter the element to insert at beginning: ");
                scanf("%d", &ele);
                insert_front(start, ele);
                break;
            }
            case 2: {
                printf("Enter the element to insert at end: ");
                scanf("%d", &ele);
                insert_end(start, ele);
                break;
            }
            case 3: {
                printf("Enter the element to insert and position: ");
                scanf("%d %d", &ele, &pos);
                insert_pos(start, ele, pos);
                break;
            }
            case 4: {
                delete_front(start);
                break;
            }
            case 5: {
                delete_end(start);
                break;
            }
            case 6: {
                display(start);
                break;
            }
            case 7: {
                exit(0);
            }
            default: {
                printf("Invalid choice\n");
            }
        }
    }
    return 0;
}