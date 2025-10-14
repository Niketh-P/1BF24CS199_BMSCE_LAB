#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define N 30
char stack[N];
int top = -1;


int priority(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    if (c == '*' || c == '/') {
        return 2;
    }
    return 0;
}

int isop(char c) {
    return isalnum(c);
}

int push(char a) {
    top++;
    stack[top] = a;
    return 0;
}
char pop() {
    char x = stack[top];
    top--;
    return x;
}

void infix_to_postfix(char* exp) {
    char postfix[N];
    int k = 0;

    for (int i = 0; i < strlen(exp); i++) {
        char current = exp[i];

        if (isop(current)) {
            postfix[k++] = current;  
        }
        else if (current == '(') {
            push(current);
        }
        else if (current == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = pop(); 
            }
            pop();
        }
        else {
            while (top != -1 && priority(stack[top]) >= priority(current)) {
                postfix[k++] = pop();
            }
            push(current);
        }
    }

    
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char exp[N];
    printf("Enter the infix expression: ");
    fgets(exp, N, stdin);
    exp[strcspn(exp, "\n")] = 0; 
    infix_to_postfix(exp);  
    return 0;
}