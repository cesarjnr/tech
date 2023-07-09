#include <stdio.h>

int main() {
    /*
        Cada caractere é representado por um conjunto de até 8 bits, ou 1 byte. O range de valores permitidos para representar um caractere vai de 0 a 255 para os 
        valores unsigned e -128 a 127 para os valores signed por conta da representação complemento de 2 que é utilizada para representar números decimais negativos 
        em bits. Porém, como vimos, valores decimais diferentes podem ser representados pelo mesmo conjunto de bits por conta do sinal, como o -128 e 128, por exemplo.
        Como consequência disso, no caso dos valores do tipo char, diferentes números decimais podem representar o mesmo caractere.
        Encode é o processo de representar um conjunto de caracteres em outro formato.
        O esquema de encoding ASCII, por exemplo, é utilizado para representar os caracteres existentes em números decimais, inclusive caracteres não imprimíveis, 
        também chamados de caracteres de controle, como por exemplo o backspace (caractere utilizado ao apagar), o tab (caractere que ocupa uma determinada 
        quantidade de espaço), etc. Esse esquema representa somente os valores signed (até o 127) pois é o suficiente para os caracteres existentes na língua 
        inglesa e, sendo assim, utilizam somente 7 bits. Para representar caracteres de outro idioma, existe o esquema extended ASCII, que adiciona representações 
        para os valores 128 até 255.
    */
    char oneCharacter = 'C';
    printf("A single character: %c\n", oneCharacter);

    char decimalRepOfChar = 67;
    printf("A single character: %c\n", decimalRepOfChar); /* Se utilizarmos o placeholder %c em uma variável declarada como char mas com um valor inteiro atribuído a
    ela, é impresso seu respectivo caractere na tabela ASCII
    */

    char signedCedilla = 97; // Representação signed
    char unsignedCedilla = 97; // Representação complemento de 2

    printf("The value 97 represents the character %c\n", unsignedCedilla);
    printf("The value -159 represents the character %c\n", signedCedilla);
}
