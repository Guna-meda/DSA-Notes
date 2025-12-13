//Binary Expression tree using stack

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
    char data;
    struct node* left;
    struct node* right;
} Node;

Node* createNode(char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* stack[100];
int top = -1;

void push(Node* node) {
    stack[++top] = node;
}

Node* pop() {
    return stack[top--];
}

Node* buildTree(char* postfix) {
    for(int i =0 ; postfix[i] != '\0'; i++){
        char c = postfix[i];

        if(isalnum(c)) {
            push(createNode(c));
        } else {
            Node* node = createNode(c);
            node->right = pop();
            node->left = pop();
            push(node);
        }
    }
    return pop();
}

int evaluate(Node* root) {
    if(root->left && root-> right == NULL) {
        return root->data - '0';
    }
    int leftVal = evaluate(root->left);
    int rightVal = evaluate(root->right);
    switch(root->data) {
        case '+': return leftVal + rightVal;
        case '-': return leftVal - rightVal;
        case '*': return leftVal * rightVal;
        case '/': return leftVal / rightVal;
    }
    return 0;
}

void inorder(Node* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

int main() {
    char postfix[] = "53+62/*35*+";
    struct Node* root = buildTree(postfix);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Evaluation Result: %d\n", evaluate(root));

    return 0;
}