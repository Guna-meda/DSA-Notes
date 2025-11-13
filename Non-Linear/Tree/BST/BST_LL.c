#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

struct Node* createNode(int value) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if(root == NULL) {
        return createNode(value);
    }
    if(value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

struct Node* findMin(struct Node* root) {
    while(root->left != NULL) {
        root = root->left;
    }
    return root; 
}

struct Node* deleteNode(struct Node* root , int key) {
    if(root==NULL) {
        return root;
    }

    if(key < root->data) {
        root->left = deleteNode(root->left , key);
    } else if(key > root -> data) {
        root-> right = deleteNode(root->right , key);
    } else {
        if (root -> left==NULL || root->right == NULL) {
            struct Node* temp = root->left ? root->left : root->right;
            free(root);
            return temp;
        } else {
            struct Node* temp = findMin(root-> right);
            root-> data = temp-> data;
            root->right = deleteNode(root-> right , temp-> data);
        }
    }
    return root;
}

void inorder(struct Node* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int values[] = {5, 3, 7, 2, 4, 6, 8};
    int n = sizeof(values) / sizeof(values[0]);
    for (int i ; i<n ; i++) {
        insert(root , values[i]);
    }
    printf("Inorder Traversal of BST: ");
    inorder(root);
    return 0;
}