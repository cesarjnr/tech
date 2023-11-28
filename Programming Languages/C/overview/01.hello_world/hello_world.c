#include <stdio.h> // Importa o arquivo stdio.h

/*
  Importações com o símbolo # seguida da palavra include e <filename> são realizadas pelo que chamamos de preprocessador. O preprocessador importa o conteúdo do
  arquivo especificado para dentro do arquivo atual.
  Arquivos com a extensão .h são o que chamamos de arquivos header. Este tipo de arquivo contém somente as declarações, ou protótipos, das funções. Isso significa
  que eles não contêm a implementação das funções, apenas a representação das mesmas.
  Os arquivos contendo a implementação das funções ficam localizados na biblioteca padrão do C. Essa biblioteca geralmente já vem instalada com os sistemas
  operacionais pois a maioria dos programas dos sistemas operacionais utilizam a linguagem C.
  Existe um programa chamado Linker que mapeia as declarações dos arquivos .h para as implementações das funções que os mesmos representam. Ele é executado por
  baixo dos panos no momento da compilação. 
*/

int main() {
    printf("Hello World");

    return 0;
}