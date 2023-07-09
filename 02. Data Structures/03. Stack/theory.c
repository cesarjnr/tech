/*

1. Definitions

  ---> A stack is a one-ended linear data structure which models a real world stack by having two primary operations, namely push and pop.
  ---> Elements in a stack is always removed and added to the top of the pile. This behavior is commonly known as Last In First Out (LIFO).
  ---> We can use stacks for:
    ---> Used by undo mechanisms in text editors;
    ---> Used in compiler syntax checking for matching brackets and braces;
    ---> Can be used to model a pile of books or plates;
    ---> Used behind the scenes to support recursion by keeping track of previous function calls;
    ---> Can be used to do a Depth First Search (DFS) on a graph.

2. Terminology

  ---> Push: add an element to the stack
  ---> Pop: remove an element from the stack

3. Complexity

The following assumes a implementation of stack using linked list.

  ---> Pushing O(1): Because we have a pointer to the top of the stack
  ---> Popping O(1): Because we have a pointer to the top of the stack
  ---> Peeking O(1): Because we have a pointer to the top of the stack
  ---> Searching O(n): Because we might have to scan all the elements in the stack

*/