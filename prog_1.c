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

#include <stdio.h>
#include <string.h>
#define MAX 100 
typedef struct {
char stack[MAX];
int top;
} Stack;
void push(Stack *s, char ch) {
    if (s->top >= MAX - 1) {
        return;
    }
    s->top++;
    s->stack[s->top] = ch;
};
char pop(Stack *s) {
    if (s->top < 0) {
    return 0;
  }
    return s->stack[s->top--];
}
int isBalanced(char *exp) {
Stack stack;
stack.top = -1;
int length = strlen(exp);   
for (int i = 0; i < length; i++) {
    char ch = exp[i];
    if (ch == '(' || ch == '{' || ch == '[') {
        push(&stack, ch);
    }
    else if (ch == ')' || ch == '}' || ch == ']'){
        if (stack.top == -1) {
            return 0;
        }
        char last = pop(&stack);
        if ((ch == ')' && last != '(') ||
            (ch == '}' && last != '{') ||
            (ch == ']' && last != '[')) {
            return 0;
        }
    }
}
return (stack.top == -1);
}
int main() {
char expression[MAX];
printf("Enter an expression: ");
fgets(expression, MAX, stdin);
expression[strcspn(expression, "\n")] = '\0';
if (isBalanced(expression)) {
    printf("The parentheses are balanced.\n");
} else {
    printf("The parentheses are not balanced.\n");
}
return 0;
};