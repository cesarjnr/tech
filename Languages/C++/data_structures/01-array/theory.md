## Static Array

### 1. Definitions

A **static array** is a fixed length container containing n elements indexable from the range [0, n-1]. By indexable we mean that each slot/index in the array can be referenced with a number.
A static array is given as contiguous chunks of memory meaning that all the addresses are adjacent.

### 2. Usage

A static array is used for:
  * storing and accessing sequential data;
  * temporarily storing objects;
  * used by IO routines as buffers;
  * lookup tables and inverse lookup tables;
  * returning multiple values from a function;
  * caching answers to subproblems in dynamic programming.

### 3. Complexity

| Operation | Complexity  | Why                                                                                                                                                                                        |
| :-------: | :---------: | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Access    | O(1)        | Because they are indexable we can directly access the elements using these indexes                                                                                                         | 
| Search    | O(n)        | Because we can potentially have to traverse all the elements in the array to find an element                                                                                               |
| Insert    | O(n)        | Because we can potentially need to shift all the existing elements to the right by one index (if the new element is being inserted at the beginning) to create a space for the new element |
| Remove    | O(n)        | Because we can potentially need to shift all the existing elements to the left by one index (if the new element is being deleted from the beginning) to fill the space left                |

### 4. Operations

* Deletion

Since a static array, in practice, has all your positions filled with some value, we don't delete anything actually. We just need a way to know the index that is available to be overwritten. And when we are "deleting" some element, we are actually telling the program that the position of that element is now available to receive another value.
So, in order to delete something from the end of an array, we just need to decrease the variable we use to control the array length.

```cpp
  // Declare an integer array of 5 elements
  int arr[5];
  int length = 0;

  // Adding elements at the first 3 indexes
  for (int i = 0; i < 3, i++) {
    arr[length] = i;
    length++
  }

  // Delete an element from the end of the array
  length--;
```

Because of this, deleting an element from the end of an array takes O(1) time.
Deleting from the start has the costliest of all deletion operations. We need to shift all elements to the left (starting with the element at index 1).

```cpp
  // Starting at index 1, we shift each element one position to the left
  for (int i = 1; i < length; i++) {
    arr[i - 1] = arr[i];
  }

  // Decrease the length of the array
  length--;
```

Because of this, deleting an element from the start of an array takes O(n) time.
For deletion at any given index, the empty space created by the deleted item will need to be filled. Each of the elements to the right of the index we're deleting at will get shifted to the left by one.

```cpp
  // Say we want to delete the element at index 1
  for (int i = 2; i < length; i++) {
    arr[i - 1] = arr[i];
  }

  // Decrease the length of the array
  length--;
```

Notice how this works exactly like deleting the first element, except that we don't touch the elements that are at lower indexes thatn the element we're deleting. So, deleting an element from anywhere takes O(n) time as well because if we need to the delete the first element of the array, we'll need to shift all elements to the left.

## Dynamic Array

### 1. Definitions

A **dynamic array** is a variable length container containing n elements indexable from the range [0, n-1].
We can implement a dynamic array using a static array. We can follow the following steps:
  * Create a static array with an initial capacity
  * Add elements to the underlying static array, keeping track of the number of elements
  * If adding another element will exceed the capacity, then create a new static array with twice the capacity and copy the original elements into it

### 2. Complexity

| Operation | Complexity  | Why                                                                                                                                                                                        |
| :-------: | :---------: | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Access    | O(1)        | Because they are indexable we can directly access the elements using these indexes                                                                                                         | 
| Search    | O(n)        | Because we can potentially have to traverse all the elements in the array to find an element                                                                                               |
| Insert    | O(n)        | Because we can potentially need to shift all the existing elements to the right by one index (if the new element is being inserted at the beginning) to create a space for the new element |
| Remove    | O(n)        | Because we can potentially need to shift all the existing elements to the left by one index (if the new element is being deleted from the beginning) to fill the space left                |
| Resize    | O(n)        | If the array is filled, we need to create another array and copy all the existing elements to this new array                                                                               |

## In-Place Operations

In-Place array operations are where we modify an array, without creating a new array. They help to reduce the space complexity of the algorithm.
In-Place array operations are a big deal for programming interviews, where there is a big focus on minimising both time and space complexity of algorithms.
