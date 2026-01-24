# Program 1 – Checking if any given mathematical expression ha balanced number of parentheses or not using stack
# 1. Data Structure Definition
This program uses a stack data structure to check whether a given mathematical expression has balanced parentheses.
The stack is implemented using:
A character array stack[MAX] to store brackets
Opening brackets (, {, and [ are pushed onto the stack.
When a closing bracket ), }, or ] is encountered, the stack is popped and checked for a matching opening bracket.
If a mismatch occurs or the stack is empty when a closing bracket is found, the expression is considered unbalanced.
After scanning the entire expression, the stack must be empty for the expression to be balanced.
# 2.Description of Functions Implemented
1. push(Stack *s, char ch)
Adds the character `ch` onto the top of the stack by incrementing `top` and storing `ch` at the new top position.
2. pop(Stack *s)
Removes and returns the top element from the stack by returning the character at `top` and then decrementing `top`. Returns `'\0'` if the stack is empty.
3. isBalanced(char *exp)
Checks if the input expression `exp` has balanced parentheses. It checks through each character, pushing opening brackets to the stack, and popping when matching closing brackets appear. Returns 1 if balanced, 0 otherwise.
4. Organization of main()
- Reads a line of input (the expression) from the user.
- Calls `isBalanced()` function to check the expression.
- Prints whether the parentheses are balanced or not.
# 4. Sample Output
the following expressions were given:
Enter an expression: ⇒a + (b − c) ∗ (d
The parentheses are not balanced.
Enter an expression: a + (b − c) 
The parenthese are balanced
Enter an expression: ⇒m + [a − b ∗ (c + d ∗ {m)]
The parentheses are not balanced.
 