//! Binary search tree insert and inorder traversal using array method

//* inserts a value into a Binary Search Tree (BST) stored in an array using heap-like indexing (0-based, left child = 2*i+1, right = 2*i+2).

#include<stdio.h>

int BST[100];

void insert(int value) {
    int i=0;
    while(i<100 && BST[i] !=0) {   // traverse until u find empty spot 
        if(value < BST[i]){ 
            i= 2*i + 1;
        } else {
            i = 2*i + 2;
        }
    }
    if(BST[i] == 0) {
        BST[i] = value;
    }
}

void inorder(int i) {
      if (i<100 && BST[i]!=0){
        inorder(2*i+1); // left child
        printf("%d ",BST[i]);
        inorder(2*i+2); // right child
    }
}

int main() {
    int values[] = {30,40,50,60,70,20};
    int n = sizeof(values) / sizeof(values[0]);

    for(int i=0;i<n;i++) {
        insert(values[i]);
    }
    printf("Inorder Traversal: ");
    inorder(0);
    printf("\n");
    return 0;
}
