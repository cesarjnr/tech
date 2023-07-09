#include <stdio.h>

int main() {
  struct point
  {
    int x, y;
  }; // Declare a struct

  struct point p1; // Declare a variable with the struct type
  struct point p2 = {0, 1}; // Declare a variable with the struct type and initialize its members

  struct address
  {
    char street[100];
    char city[50];
    char state[20];
    char cep[10];
  } my_address = {
    "Rua Quinze de Novembro",
    "Duque de Caxias",
    "Rio de Janeiro",
    "25065-135"
  }; // Declare a struct and a variable with the struct type and initialize its members

  p1.x = 1; // Assign a value to a struct member
  p1.y = 0;

  printf("P1: x = %d, y = %d\n", p1.x, p1.y);
  printf("P2: x = %d, y = %d\n", p2.x, p2.y);
  printf("%s, %s, %s - %s\n", my_address.street, my_address.city, my_address.state, my_address.cep);
}