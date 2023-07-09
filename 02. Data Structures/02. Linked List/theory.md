### 1. Definitions

A **linked list** is a sequential list of nodes that hold data which point to other nodes also containing data. The last node points to null meaning that there are no more nodes at this point.

### 2. Usage

We can use linked lists for:
  * List, queue, stack, adjacency lists for graphs implementations;
  * Creating circular lists;
  * Modeling real world objects such as trains.

### 3. Terminology

* Head: the first node in a linked list.
* Tail: the last node in a linked list.
* Pointer: reference to another node.
* Node: an object containing data and pointer(s)

### 4. Singly vs Doubly Linked Lists

Singly linked lists only hold a referente to the next node. In the implementation you always maintain a reference to the head for traversing the list.
With a doubly linked list each node holds a referente to the next and the previous node. In the implementation you always maintain a reference to the head for traversing the list.

| Type           |            Pros                                     |                  Cons                    |
| :------------: | :-------------------------------------------------: | :--------------------------------------- |
| Singly Linked  | Use less memory; simpler implementation             | Cannot easily access previous elements   |
| Doubly Linked  | Can be traversed backwards                          | Takes 2x memory                          |

### 5. Complexity

**Singly Linked**:

  | Operation            | Complexity | Why                                                                       |
  | :------------------: | :--------: | :------------------------------------------------------------------------ |
  | Access               | O(n)       | Because we can potentially have to traverse all the elements in the list  |
  | Search               | O(n)       | Because we can potentially have to traverse all the elements in the list  |
  | Insert               | O(1)       | Because we receive the node that will be used as a reference              |
  | Remove               | O(1)       | Because we receive the node that will be used as a reference              |

**Doubly Linked**:

  | Operation            | Complexity | Why                                                                       |
  | :------------------: | :--------: | :------------------------------------------------------------------------ |
  | Access               | O(n)       | Because we can potentially have to traverse all the elements in the list  |
  | Search               | O(n)       | Because we can potentially have to traverse all the elements in the list  |
  | Insert               | O(1)       | Because we receive the node that will be used as a reference              |
  | Remove               | O(1)       | Because we receive the node that will be used as a reference              |

### 6. Linked List vs Array

Linked lists should be used if you need to add or delete items frequently whereas arrays should be used if you need to access an element at a given position frequently.
