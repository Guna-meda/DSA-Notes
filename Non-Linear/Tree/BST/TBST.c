# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
    bool lthread;
    bool rthread;
} node;

node* createNode(int data) {
    node* newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->lthread = true;
    newNode->rthread = true;
    return newNode;
}

node* insert(node* root , int data) {
    node* cur = root;
    node* parent = NULL;

    node* temp = createNode(data);

    // find the parent node for insertion
    while(cur !=NULL) {
        parent = cur;
        if(data<cur->data) {
            if(cur->lthread == false) {
                cur = cur->left;
            }
        } else {
            if(cur->rthread == false) {
                cur= cur->right;
            }
        }
    }

    if(data < parent ->data) {
        temp->left = parent->left;
        temp->right = parent;
        parent->lthread = false;
        parent->left = temp;
    } else {
        temp->right = parent->right;
        temp->left = parent;
        parent->rthread = false;
        parent->right = temp;
    }
    return root;
}

void inorderTraversal (node* root) {
    node* cur = root;
    while( cur != NULL) {
        while(cur -> left != NULL) {
            cur = cur -> left;
        }
        printf("%d ", cur-> data);
        if(cur -> rthread) {
            cur = cur -> right; 
// even if right is NULL, it will go to inorder successor
// because it is the next element that we want to visit
        } else {
            cur = cur-> right;
            if(cur != NULL) {
                while(cur-> left != NULL) {
                    cur = cur -> left;
                }
            }
        }
    }
}

int main() {
    node* root = createNode(50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder Traversal of Threaded Binary Search Tree:\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}