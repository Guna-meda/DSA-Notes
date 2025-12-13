#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct node {
    int data;
    struct node *next;
};

struct hashtable {
    struct node *head;
};

struct node* createNode(int key) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = key;
    newNode->next = NULL;
    return newNode;
}

void insert(int key, struct hashtable *ht) {
    int index = key % SIZE;

    struct node *newNode = createNode(key);
    newNode->next = ht[index].head;   // Insert at beginning
    ht[index].head = newNode;

    printf("%d inserted at index %d\n", key, index);
}

void search(int key, struct hashtable *ht) {
    int index = key % SIZE;
    struct node *cur = ht[index].head;
    int pos = 1;

    while (cur) {
        if (cur->data == key) {
            printf("%d found at index %d, position %d\n", key, index, pos);
            return;
        }
        cur = cur->next;
        pos++;
    }

    printf("%d not found\n", key);
}

void deleteData(int key, struct hashtable *ht) {
    int index = key % SIZE;
    struct node *cur = ht[index].head, *prev = NULL;

    while (cur) {
        if (cur->data == key) {
            if (prev)
                prev->next = cur->next;
            else
                ht[index].head = cur->next;

            free(cur);
            printf("%d deleted successfully\n", key);
            return;
        }
        prev = cur;
        cur = cur->next;
    }

    printf("%d not found\n", key);
}

void display(struct hashtable *ht) {
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d: ", i);
        struct node *cur = ht[i].head;

        if (!cur) {
            printf("EMPTY");
        } else {
            while (cur) {
                printf("%d -> ", cur->data);
                cur = cur->next;
            }
            printf("NULL");
        }
        printf("\n");
    }
}

int main() {
    struct hashtable ht[SIZE] = {0};

    insert(10, ht);
    insert(20, ht);
    insert(15, ht);
    insert(30, ht);
    insert(47, ht);
    insert(65, ht);

    display(ht);

    search(20, ht);
    deleteData(10, ht);

    display(ht);

    return 0;
}
