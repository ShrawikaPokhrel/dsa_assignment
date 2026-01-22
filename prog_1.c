#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char stack[MAX];
    int top;
} Stack;

void push(Stack *s, char c) {  // Push character onto stack
    if (s->top < MAX - 1) {
        s->stack[++(s->top)] = c;
    }
}

char pop(Stack *s) { // Pop character from stack
    if (s->top >= 0) {
        return s->stack[(s->top)--];
    }
    return '\0';
}

int isBalanced(char *exp) {
    Stack s;
    s.top = -1;

    for (int i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(&s, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (s.top == -1)
                return 0; 
            char popped = pop(&s);
            if ((exp[i] == ')' && popped != '(') ||
                (exp[i] == '}' && popped != '{') ||
                (exp[i] == ']' && popped != '[')) {
                return 0; 
            }
        }
    }

    return (s.top == -1); // balanced (if stack is empty)
}

int main() {
    char exp[MAX];

    printf("Enter an expression: ");
    fgets(exp, MAX, stdin);

    exp[strcspn(exp, "\n")] = 0;

    if (isBalanced(exp)) {
        printf("The parentheses are balanced.\n");
    } else {
        printf("The parentheses are not balanced.\n");
    }

    return 0;
}
