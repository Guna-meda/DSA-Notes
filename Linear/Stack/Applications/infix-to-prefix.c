#include <stdio.h>
#include <ctype.h>   // for isalnum()

#define MAX 100

// Push function
void push(char *s, int *top, char x) {
    (*top)++;
    s[*top] = x;
}

// Pop function
char pop(char *s, int *top) {
    char x = s[*top];
    (*top)--;
    return x;
}

// Stack precedence
int stackprec(char ch) {
    switch (ch) {
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 4;
        case '^': return 5;
        case '(': return 0;
        case '#': return -1; // stack bottom
        default: return 8;   // for operands
    }
}

// Input precedence
int inputprec(char ch) {
    switch (ch) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 3;
        case '^': return 6;
        case '(': return 9;
        case ')': return 0;
        default: return 7;   // for operands
    }
}

// Infix to Postfix Conversion
void convert(char *infix, char *postfix) {
    char s[MAX];
    int top = -1;
    int i = 0, j = 0;

    push(s, &top, '#'); // bottom marker

    while (infix[i] != '\0') {
        char ch = infix[i];

        if (isalnum(ch)) {  // operand directly to output
            postfix[j++] = ch;
        } else {
            while (stackprec(s[top]) >= inputprec(ch)) {
                if (s[top] == '(') break;  // stop at '('
                postfix[j++] = pop(s, &top);
            }

            if (ch == ')') {
                while (s[top] != '(') {
                    postfix[j++] = pop(s, &top);
                }
                pop(s, &top); // remove '('
            } else {
                push(s, &top, ch);
            }
        }
        i++;
    }

    // Pop remaining operators
    while (s[top] != '#') {
        postfix[j++] = pop(s, &top);
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    convert(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
