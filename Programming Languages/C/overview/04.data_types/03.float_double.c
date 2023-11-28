#include <stdio.h>

int main() {
    /*
        Os tipos float, double e long double possuem os seguintes tamanhos:

            float       ---> 4 bytes (32 bits)
            double      ---> 8 bytes (64 bits)
            long double ---> 12 bytes (96 bits)

        Estes tamanhos podem variar de sistema para sistema.
        Existem duas formas de representar números fracionários: ponto fixo (fixed point) e ponto flutuante (floating point).
        Utilizando a representação do ponto fixo, determinamos previamente uma quantidade fixa igual de bits para representar tanto a parte inteira como a parte fracionária, 
        ou seja, temos um ponto fixo. Por exemplo, uma palavra de 8 bits teria 4 bits disponíveis para a parte inteira e 4 para a parte fracionária. Se o valor da parte 
        decimal ultrapassar o range máximo, ele é arredondado para o valor mais próximo possível que possa ser representado por 4 bits o que, consequentemente, reduz a 
        precisão do valor. A parte fracionária sempre tem um range de valores maior pois não possui um sinal ocupando 1 bit como é o caso da parte inteira.
        A representação de ponto flutuante, por outro lado, é a mais utilizada nos dias atuais por conta da sua precisão mais apurada. Com ela, o número de bits disponíveis 
        não define com antecedência a quantidade de bits disponíveis para a parte inteira ou fracionária e, consequentemente, o range pode variar. Por exemplo, em uma 
        palavra de 8 bits, poderíamos ter 2 bits para a parte inteira (que na representação de ponto flutuante chamamos de expoente) e 6 bits para a parte fracionária (que 
        na representação de ponto flutuante chamamos de mantissa). Perceba que com a mesma quantidade de bits conseguimos aumentar o range de valores disponíveis para a 
        parte decimal que nos permite ter uma precisão maior.
        Vejamos por exemplo o número 1.16. Utilizando a representação de ponto fixo e uma palavra de 8 bits, não seria possível representar este número pois o número 16 
        ocupa 5 bits (10000). Ele seria arredondado para 15 e com isso perderíamos precisão. A parte inteira, que é 1, ocupa apenas 2 bits(01 - complemento de 2) mas mesmo 
        assim possui 4 bits fixos nesta representação. Por outro lado, com a notação de ponto flutuante, é possível alocar somente os 2 bits necessários para o número 1 e 
        deixar os outros 6 para a parte fracionária.
        Hoje a representação de ponto flutuante é amplamente utilizada e segue o padrão IEEE 754. O padrão IEEE 754 do ponto flutuante estabelece normas a serem seguidas 
        para representar um número decimal em binário. Suas normas são as seguintes:

        - Precisão simples (32 bits): sinal = 1 bit, expoente = 8 bits, mantissa = 23 bits
        - Precisão simples estendida (>= 43 bits): sinal = 1 bit, expoente >= 11 bits, mantissa >= 32 bits
        - Precisão dupla (64 bits): sinal = 1 bit, expoente = 11 bits, mantissa = 52 bits
        - Precisão dupla estendida (>= 79 bits): sinal = 1 bit, expoente >= 15 bits, mantissa => 64 bits

        Podemos perceber que, quanto maior a precisão, mais bits são necessários.

        O passo a passo para representar um número decimal em ponto flutuante no padrão IEEE 754 simples é o seguinte:
        
        1. São convertidas para binário as partes inteira e fracionária. Utilizando o número 263.3 como exemplo, teríamos:

            263 ---> 100000111
            0.3 ---> 0100110011...

        Então, 263 e 0.3, em binário, é 100000111.010011...

        2. Depois, utilizamos a notação científica, que nos ajudará a determinar os bits que representam o expoente e os bits que representam a mantissa:

            100000111.010011... ---> 1.00000111010011... x 2^8

        3. Agora, só precisamos seguir as normas que padrão IEEE 754 simples (32 bits) determina:

            x       xxxxxxxx        xxxxxxxxxxxxxxxxxxxxxxx
            sinal  expoente + bias    mantissa

        - O bit referente ao sinal será 0 pois nosso número 263.3 é positivo.

        - O sinal que determinamos acima é referente ao número por completo. Quando vamos determinar os bits referente ao expoente, precisamos também levar em consideração
        que o mesmo pode ser positivo ou negativo. O padrão IEEE 754 não utiliza a representação complemento de 2. Ele utiliza o que é conhecido como representação excesso, 
        que consiste em utilizar um valor conhecido como bias. O bias é calculado elevando 2 à quantidade de bits disponíveis para o expoente, divindo o resultado por 2 e 
        subtraindo 1. Ou seja, para o padrão de precisão simples, onde temos 8 bits para os expoentes, temos o bias sendo:

            2^8 / 2 - 1 = 256 / 2 - 1 = 128 - 1 = 127

        Então sempre teremos o bias como sendo 127 para o padrão de precisão simples.
        Então, para representarmos nosso expoente em binário no padrão de precisão simples, levando seu sinal em consideração, precisamos somar o expoente da notação ao bias e
        converter o resultado para binário:

            8 + 127 = 135 ---> 10000111

        Ou seja, a parte inteira do número (263) é representada pelo binário 10000111 no padrão IEEE 754.

        - A mantissa é todo o binário que ficou após o ponto, após a notação ter sido realizada.

        Então, 263.3, no padrão IEEE 754 de precisão simples, é representado pelo binário:

            01000011100000111010011001100110
    */

    float var1 = 3.1415926535897932;
    double var2 = 3.1415926535897932;
    long double var3 = 3.141592653589793213456;

    printf("O tamanho de uma variável float (precisao simples) é de %ld bytes\n", sizeof(float));
    printf("O tamanho de uma variável double (precisao dupla) é de %ld bytes\n", sizeof(double));
    printf("O tamanho de uma variável long double (precisao dupla estendida) é de %ld bytes\n", sizeof(long double));
    printf("Valor de var1: %.16f \n", var1);
    printf("Valor de var2: %.21lf \n", var2);
    printf("Valor de var3: %.21Lf \n", var3);

    /*
        Podemos reparar acima que a diferença entre os tipos é sua precisão. A partir de determinada quantidade de casas decimais, conforme a parte fraconária cresce, podemos 
        perceber que o valor começa a ficar diferente. Então, se você precisa de uma precisão alta em um número decimal com uma quantidade alta de casas decimais, prefira os 
        tipos double ou long double, caso contrário, utilize o float pois economiza espaço
    */

    int var4 = 4 / 9;
    printf("The result of dividing 4 by 9 is: %d \n", var4);
    /*
        O resultado será 0 pois a divisão de 4 por 9 resulta em um número fracionário (0.44) e, como estamos realizando a divisão de 2 números inteiros, seu resultado será 
        truncado (0).
    */

    float var5 = 4 / 9;
    printf("The result of dividing 4 by 9 is: %.2f \n", var5);
    /*
        O resultado será 0.00. Novamente, o resultado estará incorreto pois estamos realizando uma divisão de números inteiros. A diferença é que aqui estamos armazenando o 
        resultado (0) em uma variável do tipo float que nos permite representar valores decimais. Quando dizemos que queremos exibir 2 casas após o ponto flutuante, como não 
        haverá nenhum valor decimal, elas são preenchidas com 0.
    */

    float var6 = 4.0 / 9.0;
    printf("The result of dividing 4.0 by 9.0 is: %.2f \n", var6);
    /*
        Esta é a maneira correta de realizar uma divisão que resulte em números decimais, armazenar seu resultado e representá-lo da forma correta. Adicionando um ponto 
        flutuante mais um valor decimal a um número inteiro faz com que os valores sejam, por padrão, representados na precisão dupla. Ou seja, ao adicionarmos o .0 aos 
        inteiros 4 e 9, estamos transformando-os em valores do tipo double. Se você quiser que eles sejam representados na precisão simples - transformá-los no tipo float - 
        adicione um f após a parte decimal: 4.0f, 9.0f.
    */

    return 0;
}