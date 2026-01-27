# Program 4 – Implementation of Insertion and Deletion Operations in a Doubly Linked List

## 1. Data Structure Definition

This program uses a **doubly linked list** data structure defined as follows:

Node Structure (`Node`)

  - Contains an integer data field `data`
  - Contains a pointer `prev` pointing to the previous node in the list
  - Contains a pointer `next` pointing to the next node in the list
- The doubly linked list is managed using a global pointer `head`, which points to the first node of the list

The presence of both `prev` and `next` pointers allows traversal in both forward and backward directions

## 2. Description of Functions Implemented

`void insertBegin(int value)`

   -Inserts a new node with value `value` at the **beginning** of the doubly linked list
  - Dynamically allocates memory for the new node
  - Sets the new node’s `prev` pointer to `NULL` and its `next` pointer to the current head
  - Updates the previous head’s `prev` pointer to the new node
  - Updates `head` to point to the newly inserted node

`void insertEnd(int value)`

   -Inserts a new node with value `value` at the **end** of the doubly linked list
   -If the list is empty, the new node becomes the head
   -Otherwise, traverses the list until the last node and links the new node after it
   -Updates the `prev` pointer of the new node to point to the last node

`void insertAfterNode(Node* pre, int value)`

  -Inserts a new node with value `value` **after a given node** `pre`
  -If the given node is `NULL`, the function returns without performing insertion
  - Sets the new node’s `prev` pointer to `pre` and its `next` pointer to `pre->next`
  - Adjusts the surrounding nodes’ pointers to maintain the list structure

`void deleteBegin()`

  - Deletes the **first node** of the doubly linked list
  - If the list is empty, the function returns without action
  - Updates `head` to the second node and sets its `prev` pointer to `NULL`
  - Frees the memory occupied by the deleted node

`void deleteEnd()`

  - Deletes the **last node** of the doubly linked list
  - If the list contains only one node, it frees the node and sets `head` to `NULL`
  - Otherwise, traverses to the last node, updates the second-last node’s `next` pointer to `NULL`, and frees the last node

`void display()`

  -Traverses the list from `head` to the end
  -Prints the data of each node in sequence

## 3. Organization of `main()`

-Initializes the doubly linked list as empty (`head = NULL`)
- Inserts a node with value `15` at the beginning of the list using `insertBegin()`
- Inserts another node with value `15` at the end using `insertEnd()`
- Inserts a node with value `20` after the first node using `insertAfterNode()`
- Deletes the first node using `deleteBegin()`
- Deletes the last node using `deleteEnd()`
- Displays the final contents of the list using `display()`
- Returns 0 to indicate successful execution

## 4. Sample Output

20
