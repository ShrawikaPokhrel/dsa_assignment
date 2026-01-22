# Program 1 – Checking if any given mathematical expression ha balanced number of parentheses or not using stack

# 1. Data Structure Definition

This program uses a *stack* data structure which is implemented through an array and a `top` variable to keep track of the current position in the stack.

- The stack stores opening brackets such as: `(`, `{`, `[`.
- `top` keeps the index of the last inserted element.
- When an opening bracket is found, it is pushed onto the stack.
- When a closing bracket is found, the stack is popped and checked for a matching opening bracket.

# 2.Description of Functions Implemented

1. push(Stack *s, char c)

Adds the character `c` onto the top of the stack by incrementing `top` and storing `c` at the new top position.

2. pop(Stack *s)

Removes and returns the top element from the stack by returning the character at `top` and then decrementing `top`. Returns `'\0'` if the stack is empty.

3. isBalanced(char *exp)

Checks if the input expression `exp` has balanced parentheses. It checks through each character, pushing opening brackets to the stack, and popping when matching closing brackets appear. Returns 1 if balanced, 0 otherwise.

4. Organization of main()

- Reads a line of input (the expression) from the user.
- Calls `isBalanced()` to check the expression.
- Prints whether the parentheses are balanced or not.

# 4. Sample Output
the following expressions were given:
Enter an expression: ⇒a + (b − c) ∗ (d
The parentheses are not balanced.
Enter an expression: a + (b − c) 
The parenthese are balanced
Enter an expression: ⇒m + [a − b ∗ (c + d ∗ {m)]
The parentheses are not balanced.
