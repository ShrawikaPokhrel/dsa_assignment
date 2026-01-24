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