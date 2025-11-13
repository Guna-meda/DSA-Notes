// balanced and unbalanced parentheses using stack
// what is it? balanced paranthesis means every opening paranthesis has a closing paranthesis
// example: (()), {()}, [()], etc are balanced paranthesis
// unbalanced: ((), {()}, [()), etc are unbalanced paranthesis
// if top = -1 then it is balanced paranthesis
// if top != -1 then it is unbalanced paranthesis

#include <stdio.h>

int main() {
    int s[100];
    int top = -1;
    char exp[100];
    printf("Enter the expression: ");
    scanf("%s", exp);
    int i;
    for(i=0;exp[i] != '\0';i=i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            top++;
            s[top] = exp[i];
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if( exp[i] == ')' && s[top] == '(' ) {
                top--;
            } else if ( exp[i] == '}' && s[top] == '{' ) {
                top--;
            } else if ( exp[i] == ']' && s[top] == '[' ) {
                top--;
            } else {
                printf("Unbalanced parentheses\n");
                return 0;
            }
        }
    }
    if(top == -1) {
        printf("Balanced parentheses\n");
    } else {
        printf("Unbalanced parentheses\n");
    }
    return 0;
}