#include <stdlib.h>
#include <stdio.h>

int main() {
  int arr1[1]; // Declara um array estático com uma posição
  arr1[0] = 1; // Inicializa o valor do index 0

  int arr2[] = { 2, 3 }; // Declara e inicializa os valores do array sem especificar o tamanho
  int arr3[3] = { 4, 5, 6 }; // Declara e inicializa os valores do array especificando o tamanho do array

  printf("Array 1\n");

  for (int i = 0; i < 1; i++) {
    printf("Array value in index %d: %d\n", i, arr1[i]);
  }

  printf("Array 2\n");

  for (int i = 0; i < 2; i++) {
    printf("Array value in index: %d: %d\n", i, arr2[i]);
  }
  
  printf("Array 3\n");

  for (int i = 0; i < 3; i++) {
    printf("Array value in index %d: %d\n", i, arr3[i]);
  }

  /*
    Podemos utilizar o operador sizeof para iterar o array. O operador sizeof retorna o tamanho expresso em bytes. Então podemos pegar o tamanho do array, dividi-lo pelo tamanho do elemento no índice atual e verificar se o resultado é
    maior que a variável de controle. Por exemplo, se temos um array de 2 elementos int, o tamanho do array é 8. Quando estamos iterando o índice 0, a variável de controle é 0. 0 é menor do que o tamanho do array (8) dividido pelo tamanho
    do elemento do índice (4), que é 2. Na próxima iteração, a variável de controle é 1. 1 é menor do que o tamanho do araray (8) dividido pelo tamanho do element do índice (4). Na próxima iteração, a variável de controle é 2. 2 não é
    maior do que o tamanho do array (8) dividido pelo tamanho do elemento do índice (4), então o loop é encerrado.
  */

  int arr4[4] = { 7, 8, 9, 10 };

  printf("Array 4\n");

  for (int i = 0; i < (sizeof(arr4) / sizeof(arr4[i])); i++) { 
    printf("Array vaue in index %d: %d\n", i, arr4[i]);
  }

  return 0;
}
