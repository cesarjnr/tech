#include <stdio.h>
#include <limits.h> // Fornece constantes simbólicas utilizadas para representar os valores mínimo e máximo de qualquer tipo de dado de acordo com o sistema

int main() {
    printf("The size of a variable of integer type is %zu bytes\n", sizeof(int));
    printf("The minimum size (short) of a variable of integer type is %zu bytes\n", sizeof(short int));
    printf("The maximum size (long) of a variable of integer type is %zu bytes\n", sizeof(long int));

    int var1 = INT_MIN, var2 = INT_MAX;
    printf("Range of signed integer is from: %d to %d\n", var1, var2);

    unsigned int var3 = 0, var4 = UINT_MAX;
    printf("Range of unsigned integer is from: %u to %u\n", var3, var4);

    short int var5 = SHRT_MIN, var6 = SHRT_MAX;
    printf("Range of short signed integer is from: %d to %d\n", var5, var6);

    short unsigned int var7 = 0, var8 = USHRT_MAX;
    printf("Range of short unsigned integer is from: %u to %u\n", var7, var8);

    long int var9 = LONG_MIN, var10 = LONG_MAX;
    printf("Range of long signed integer is from: %li to %li\n", var9, var10);

    long unsigned int var11 = 0, var12 = ULONG_MAX;
    printf("Range of long unsigned integer is from: %lu to %lu\n", var11, var12);

    long long int var13 = LLONG_MIN, var14 = LLONG_MAX;
    printf("Range of long long signed integer is from: %lld to %lld\n", var13, var14);

    long long unsigned int var15 = 0, var16 = ULLONG_MAX;
    printf("Range of long long unsigned integer is from: %llu to %llu\n", var15, var16);

    /*
        Se tentarmos exceder os valores delimitados pelo range, obteremos resultados menores. Isso acontece porque esses valores ultrapassam a quantidade de bits
        anteriormente alocada para armazenar os valores permitidos dentro do range. Quando tentamos armazenar um valor maior do que o permitido pelo range, novos
        bits (1) são acrescentados à esquerda e os bits originais que representam os valores permitidos no range são "resetados".
        Sendo assim, esse valor fora do range, representado somente pelos bits disponíveis dentro do range, equivale a outro valor. Vejamos um exemplo para ficar
        mais claro:

            2^2     2^1     2^0 ---> 3 bits
            0       0       0   ---> 0
            0       0       1   ---> 1
            0       1       0   ---> 2
            0       1       1   ---> 3
            1       0       0   ---> 4
            1       0       1   ---> 5
            1       1       0   ---> 6
            1       1       1   ---> 7

        Olhando a tabela acima, temos um exemplo utilizando 3 bits. Vemos que com 3 bits podemos representar os valores de 0 a 7.
        Se tentarmos representar o valor 8 com 3 bits acontece o seguinte: como não é possível representar o valor 8 somente com 3 bits um novo bit (1) 
        é adicionado à esquerda, pois só é possível representar o valor 8 com 4 bits e, além disso, os 3 bits já existentes são "resetados" pois a
        representação do valor 8 em bits é "1000".
        Sendo assim, a representação do valor 8 com apenas 3 bits seria 000 que, consequentemente, equivale ao número 0.

        4 bits --->    2^3     (2^2     2^1     2^0)    ---> 3 bits
            8           1      ( 0       0       0 )    ---> 0
            9           1      ( 0       0       1 )    ---> 1
            10          1      ( 0       0       1 )    ---> 2
            11          1      ( 0       1       0 )    ---> 3

        Repare que a lógica segue a mesma para os valores acima de 8. Como não é possível representá-los somente com 3 bits, o bit 1 é acrescentado à esquerda e os
        3 bits finais vão se alternando até atingir a última combinação possível.
        Para ficar mais claro, podemos entender isso utilizando a analogia de um relógio. O relógio tem um range de 1 a 12. Quando ele chega a 12, ele retorna ao 1.
        É exatamente da mesma maneira que acontece quando excedemos os valores do range da variável. Seguindo essa analogia, se salvarmos um valor menor do que 0 
        para um unsigned int, o valor armazenado será 4294967295, pois como 0 é o valor mínimo do range, ele retorna ao seu valor máximo.
    */
    unsigned int var17 = 4294967296;
    printf("The value of the variable var17 is: %u\n", var17); // O valor será 0 pois um inteiro unsigned só armazena até o valor 4294967295

    unsigned int var18 = -1;
    printf("The value of the variable var18 is: %u\n", var18); // O valor será 4294967295 pois o menor valor possível para um unsigned int é 0

    /*
        Da mesma forma funciona para os valores permitidos no range de signed int. Após o valor máximo, ele retorna ao valor mínimo e abaixo do valor mínimo, ele
        retorna o valor máximo
    */
    int var19 = 2147483648;
    printf("The value of the variable var19 is: %d\n", var19); // O valor será -2147483648 pois o maior valor possível para um signed int é 2147483647

    int var20 = -2147483649;
    printf("The value of the variable var20 is: %d\n", var20); // O valor será 2147483647 pois o menor valor possível para um signed int é 2147483648

    /* 
        Os valores negativos são representados pelo que chamamos de complemento de 2. O complemento de 2 é a forma de representar valores negativos em bits.
        É adicionado um bit (1) à esquerda do bit mais significativo (o último bit da esquerda), os bits originais são invertidos e, por fim, é somado 1 bit a 
        esse resultado.
        Por exemplo, o número 127 é representado pelo seguinte conjunto de bits:

            1111111

        O número -127 precisa ser representado pelo complemento de 2, que funciona da seguinte maneira:

            (1)1111111 ---> Adiciona o bit 1 à esquerda do MSB (bit mais significativo)
            10000000 ---> Os bits originais são invertidos
            10000001 ---> É somado 1 bit ao resultado da operação anterior

        Portanto, temos que -127 é representado pelo conjunto de bits 10000001.
        Como o complemento de 2 é apenas uma representação - quando não definimos unsigned antes do tipo da variável, a memória sabe que se trata de uma 
        representação utilizando o complemento de 2 pois sabe que valores negativos poderão ser utilizados - podemos dizer que um mesmo conjunto de bits pode 
        representar dois valores diferentes, dependendo da representação que está sendo utilizada.
        Por exemplo, os valores -127 e 129 são representados pelo mesmo conjunto de bits: 10000001. Os valores -128 e 128 são representados pelo conjunto de 
        bits: 10000000.
        É exatamente por esse motivo que temos ranges diferentes para os valores signed e unsigned. Quando temos valores signed, o bit 1 mais significativo sempre 
        representará o sinal dos valores negativos. Com isso, os 7 bits restantes é que representarão o valor propriamente dito.
    */

    return 0;
}