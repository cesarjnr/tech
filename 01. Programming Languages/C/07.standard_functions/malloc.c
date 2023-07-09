#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  /*
    The malloc function allows us to work with dynamic memory allocation. It is a function from the stdlib.h library that receives integers as arguments that wil represent the number of bytes we want to allocate. This function returns 
    a pointer holding the allocated block address. Its syntax is:

      void *malloc(size_t);

    The pointer returned by this function does not have a specific type (like int, float, struct, etc.), it returns the memory block address that was allocated, treated as a void type. As we've already seen, pointers variables need to know 
    which variable type they will point to, so we need to cast this return before assigning it to a pointer variable. For example, if we want to allocate a memory block for integers, we do the following:

    (int *) malloc(size_t);
  */

  char *ptr;
  ptr = (char *) malloc(21); // allocate 21 bytes of memory to hold char values and return a pointer to the first char address
  *ptr = 'C';

  printf("Address stored in ptr variable: %p\n", ptr);

  /*
    A good practice is to avoid using numbers to set the number of allocated bytes. We can use the sizeof operator to correctly make the allocation depending on the data type that will be stored in the memory block.
  */

  char *ptr2;
  ptr2 = (char *) malloc(5 * sizeof(char)); // allocate 10 or 20 bytes, depending on the machine
  strcpy(ptr2, "Cesar");

  printf("Address stored in ptr2 variable: %p\n", ptr2);
  printf("Value stored in ptr2 variable: %s\n", ptr2);

  return 0;
}
