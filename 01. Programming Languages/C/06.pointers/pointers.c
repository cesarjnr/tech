#include <stdio.h>

int main() {
  /*
    A pointer is a variable whose value is the address of another variable. Like any variable or constant, you must declare a pointer before using it to store any variable address. The general form of a pointer declaration is:

      type *var_name;

    Here, type is the pointer's base type; it must be a valid C data type and var_name  is the name of the pointer variable. The asterisk is being used to designate a variable as a pointer. Take a look at some of the valid pointer 
    declarations:

      int *ip;   ---> pointer to an integer
      double *dp ---> pointer to a double
      float *fp  ---> pointer to a float
      char  *ch  ---> pointer to a character

    The actual data type of the value of all pointers, whether integer, float, character, or otherwise, is the same, a long hexadecimal number that represents a memory address. The only difference between pointers of different data types 
    is the data type of the variable or constant the the pointer points to.
  */

  int var = 20; // variable declaration
  int *ip; // pointer variable declaration

  ip = &var; // store the address of var in the pointer variable

  printf("Address of var variable: %p\n", &var);
  printf("Address stored in ip variable: %p\n", ip);
  printf("Value of *ip variable: %d\n", *ip);

  int arr1[2] = { 1, 2 };
  int arr2[3] = { 3, 4, 5 };
  int *ptrarr1 = arr1; // declare a pointer for an element of an array and store the address of the array index 0 element
  int (*ptrarr2)[3] = &arr2; // declare a pointer for an array of 3 integers and store the address of the whole array

  printf("Value of ptrarr1 variable: %p\n", ptrarr1);
  printf("Size of ptrarr1: %lu bytes\n", sizeof(ptrarr1));
  printf("Size of *ptrarr1: %lu bytes\n", sizeof(*ptrarr1));
  printf("Value of ptrarr2 variable: %p\n", ptrarr2);
  printf("Size of ptrarr2: %lu bytes\n", sizeof(ptrarr2));
  printf("Size of *ptrarr2: %lu bytes\n", sizeof(*ptrarr2));

  return 0;
}
