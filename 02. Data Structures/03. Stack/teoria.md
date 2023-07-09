### 1. Definições

**Stack (Pilha)** é uma estrutura de dados linear que segue uma ordem particular em que as operações são performadas. A ordem pode ser LIFO (Last In First Out) ou FILO (First In First Out). LIFO implica que o elemento que é inserido por último é o primeiro a sair enquanto que FILO implica que o elemento que é inserido primeiro é o primeiro a sair.
Para ser implementada, é necessário manter um ponteiro para o topo da stack, que é o último elemento a ser inserido porque podemos acessar apenas o elemento no topo da stack.

### 2. Operações Básicas

* Push: inserir um elemento na stack;
* Pop: remover um elemento da stack;
* Top: retorna o elemento do topo da stack;
* IsEmpty: retorna se a stack está vazia;
* Size: retorna o tamanho da stack.

**Push**

Adiciona um elemento à stack. Se a stack está cheia, então 