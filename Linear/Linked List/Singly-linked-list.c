#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} NODE;

typedef struct list {
    NODE *head;
} LIST;
//head is a pointer to the first node of the list

//to initialize the list
void init_list(LIST *ptr) {
    ptr -> head = NULL;
}

void insert_front(LIST *ptr , int ele) {
    NODE *temp = malloc(sizeof(NODE));
    temp->data = ele;
    temp->link = ptr -> head;
    ptr -> head = temp;
}

void insert_end(LIST *ptr , int ele){
    NODE *temp = malloc(sizeof(NODE));
    temp->data = ele;
    temp->link = NULL;
    if (ptr -> head == NULL) {
        ptr -> head = temp;
    } else {
        NODE *current = ptr -> head;
        while (current -> link != NULL) {
            current = current -> link;
        }
        current -> link = temp;
    }
}

void insert_pos(LIST *ptr , int ele , int pos){
    NODE *temp = malloc(sizeof(NODE));
    temp->data = ele;
    temp->link = NULL;
    if (pos == 0) {
        temp->link = ptr -> head;
        ptr -> head = temp;
    } else {
        NODE *current = ptr -> head;
        for (int i = 0; i < pos - 1 && current != NULL; i++) {
            current = current -> link;
        }
        if (current == NULL) {
            printf("Position out of bounds\n");
            free(temp);
        } else {
            temp->link = current -> link;
            current -> link = temp;
        }
    }
}

void delete_front(LIST *ptr , int x){
    if (ptr -> head == NULL) {
        printf("List is empty\n");
    } else {
        int x = ptr -> head -> data;
        NODE *first = ptr -> head;
        NODE *second = first -> link;
        free(first);
        ptr -> head = second;
        printf("Deleted element is %d\n", x);
}
}

void delete_end(LIST *ptr , int x){
    if(ptr->head == NULL) {
        printf("List is empty\n");
    } else {
        
        if(ptr -> head -> link == NULL) {
            free(ptr -> head);
            ptr -> head = NULL;
            printf("Deleted element is %d\n", x);
            return;
        }
        NODE *cur= ptr -> head;
        NODE *prev = NULL;
        while(cur -> link != NULL){
            prev=cur;
            cur=cur -> link;
        }
        int x = cur->data;
        free(cur);
        prev -> link = NULL;
        printf("Deleted element is %d\n", x);
    }
}

void delete_pos(LIST *ptr , int x , int pos){
    if (ptr -> head == NULL) {
        printf("List is empty\n");
    } else {
        if(pos == 0){
            NODE *first = ptr -> head;
             ptr -> head = first -> link;
            int x = first->data;
            free(first);
            printf("Deleted element is %d\n", x);
        } else {
            NODE *cur = ptr -> head;
            NODE *prev = NULL;
            for(int i = 0; i < pos && cur != NULL; i++){
                prev = cur;
                cur = cur -> link;
            }
            if(cur == NULL){
                printf("Position out of bounds\n");
            } else {
                prev -> link = cur -> link;
                int x = cur->data;
                free(cur);
                printf("Deleted element is %d\n", x);
            }
        }
    }
}

void sort_list(LIST *ptr){
    if(ptr -> head == NULL) {
        printf("List is empty\n");
    } else {
        NODE *i, *j;
        int temp;
        for(i = ptr -> head; i != NULL; i = i -> link) {
            for(j = i -> link; j != NULL; j = j -> link) {
                if(i -> data > j -> data) {
                    temp = i -> data;
                    i -> data = j -> data;
                    j -> data = temp;
                }
            }
        }
        printf("List sorted\n");
    }
}

void display(LIST *ptr) {
    if(ptr -> head == NULL) {
        printf("List is empty\n");
    } else {
        NODE *current = ptr -> head;
        while (current != NULL) {
            printf("%d -> ", current -> data);
            current = current -> link;
        }
        printf("NULL\n");
    }
}

void count_nodes(LIST *ptr){
    if(ptr->head == NULL) {
        printf("List is empty\n");
    } else {
        int count = 0;
        NODE *current = ptr -> head;
        while (current != NULL) {
            count++;
            current = current -> link;
        }
        printf("Number of nodes in the list: %d\n", count);
    }
}

void delete_particular(LIST *ptr , int x){
    if(ptr -> head == NULL) {
        printf("List is empty\n");
    } else {
        NODE *cur = ptr -> head;
        NODE *prev = NULL;
        while(cur != NULL && cur -> data != x) {
            prev = cur;
            cur = cur -> link;
        }
        if(cur == NULL) {
            printf("Element %d not found in the list\n", x);
        } else {
            if(prev == NULL) {
                ptr -> head = cur -> link;
            } else {
                prev -> link = cur -> link;
            }
            printf("Deleted element is %d\n", cur->data);
            free(cur);
        }
    }
}

void reverse_list(LIST *ptr){
    if(ptr -> head == NULL) {
        printf("List is empty\n");
    } else {
        NODE *prev = NULL;
        NODE *cur = ptr -> head;
        NODE *next = NULL;
        while(cur != NULL) {
            next = cur -> link;
            cur -> link = prev;
            prev = cur;
            cur = next;
        }
        ptr -> head = prev;
        printf("List reversed\n");
    }
}
//example understanding of reverse function
//if we have a list 1->2->3->NULL
//initially prev = NULL, cur = 1, next = NULL
//after first iteration: prev = 1, cur = 2, next = 2
//after second iteration: prev = 2, cur = 3, next = 3
//after third iteration: prev = 3, cur = NULL, next = NULL
//finally, head = 3


int main() {
    int ch , ele , x , pos;
    LIST *start = malloc(sizeof(LIST));
    init_list(start);
    printf("Enter your choice:\n1.Insert at beginning\n2.Insert at end\n3.Insert at position\n4.Delete from beginning\n5.Delete from end\n6.Delete from position\n7.Display\n8.Sort\n9.Count nodes\n10.Delete a particular node\n11.Reverse the list\n12.Exit\n");
    while (1) {
        printf("Enter your choice");
        scanf("%d",&ch);
        
        switch (ch) {
        case 1: {
            printf("Enter the element to insert at beginning: ");
            scanf("%d", &ele);
            insert_front(start , ele);
            break;
        }
        case 2: {
            printf("Enter the element to insert at end: ");
            scanf("%d", &ele);
         insert_end(start , ele);
            break;
        }
        case 3: {
            printf("Enter the element to insert and position: ");
            scanf("%d %d", &ele , &pos);
            insert_pos(start , ele , pos);
            break;
        }
        case 4: {
            delete_front(start , x);
            break;
        }
        case 5: {
            delete_end(start , x);
            break;
        }
        case 6: {
            printf("Enter the position to delete: ");
            scanf("%d", &pos);
            delete_pos(start , x , pos);
            break;
        }
        case 7: {
            display(start);
            break;
        }

        case 8: {
            sort_list(start);
            break;
        }
        case 9: {
            count_nodes(start);
            break;
        }
        case 10: {
            printf("Enter the element to delete: ");
            scanf("%d", &x);
            delete_particular(start , x);
            break;
        }
        case 11: {
            reverse_list(start);
            break;
        }
        case 12: {
            exit(0);
        }
        default:
            printf("Invalid choice\n");
            break;
    }

    }
    return 0;
}