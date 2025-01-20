#include <stdio.h>

int var = 1; // Variáveis globais são variáveis que não estão no escopo de nenhuma função

int outsideFn();

int main() {
  /* O motivo de não conseguirmos acessar variáveis de escopo local fora de seu escopo é porque quando a execução de seu escopo termina ela é automaticamente 
  destruída. È por isso que, se tivermos um escopo dentro do outro, conseguimos acessar uma variável do escopo de fora no escopo de dentro, pois o escopo de fora 
  ainda está em execução. Porém, não conseguimos acessar uma variável do escopo de dentro no escopo de fora, pois o escopo de dentro irá ser inteiramente executado 
  antes do escopo de fora continuar sua execução. */

  int var = 2;
  int var2 = 3;

  {
      int var2 = 4;
      printf("Another scope inside the main function scope (local variable): %d\n", var); /* Imprime 4 pois variáveis de escopo local sempre levam preferência sobre 
      às de escopo externo ou global. */
  }

  printf("Main function scope: %d\n", var2); // Imprime 3 pois variáveis de escopo local sempre levam preferência sobre às de escopo externo ou global
  printf("Main function scope: %d\n", var); // Imprime 2 pois variáveis de escopo local sempre levam preferência sobre às de escopo externo ou global

  outsideFn();

  return 0;
}

int outsideFn() {
  printf("OutsideFn function scope: %d\n", var); /* Imprime 1 pois, apesar de ser chamada pela função main, a função outsideFn não faz parte do escopo da função 
  main e, consequentemente, não tem acesso às variáveis da mesma. */
}
