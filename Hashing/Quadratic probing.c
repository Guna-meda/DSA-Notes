#include <stdio.h>
#define SIZE 10

struct node {
    int data;
    int flag;   // 0 = empty, 1 = occupied
};

void initialize(struct node *ht) {
    for (int i = 0; i < SIZE; i++) {
        ht[i].flag = 0;
        ht[i].data = 0;
    }
}

void insert(int key, struct node *ht) {
    int i = 0, index;

    while (i < SIZE) {
        index = (key % SIZE + i * i) % SIZE;   // quadratic probing

        if (ht[index].flag == 0) {
            ht[index].data = key;
            ht[index].flag = 1;
            printf("%d inserted at index %d\n", key, index);
            return;
        }

        i++;
    }

    printf("Table full! Cannot insert %d\n", key);
}

void search(int key, struct node *ht) {
    int i = 0, index;

    while (i < SIZE) {
        index = (key % SIZE + i * i) % SIZE;

        if (ht[index].flag == 1 && ht[index].data == key) {
            printf("%d found at index %d\n", key, index);
            return;
        }

        i++;
    }

    printf("%d not found in table\n", key);
}

void display(struct node *ht) {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (ht[i].flag == 1)
            printf("%d → %d\n", i, ht[i].data);
        else
            printf("%d → EMPTY\n", i);
    }
}

int main() {
    struct node hashTable[SIZE];
    initialize(hashTable);

    insert(5, hashTable);
    insert(15, hashTable);
    insert(25, hashTable);
    insert(49, hashTable);
    insert(59, hashTable);

    display(hashTable);

    search(15, hashTable);
    search(35, hashTable);

    return 0;
}
