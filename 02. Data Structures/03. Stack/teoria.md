### 1. Definições

**Stack (Pilha)** é uma estrutura de dados linear que segue uma ordem particular em que as operações são performadas. A ordem pode ser LIFO (Last In First Out) ou FILO (First In First Out). LIFO implica que o elemento que é inserido por último é o primeiro a sair enquanto que FILO implica que o elemento que é inserido primeiro é o primeiro a sair.
Para ser implementada, é necessário manter um ponteiro para o topo da stack, que é o último elemento a ser inserido porque podemos acessar apenas o elemento no topo da stack.

### 2. Aplicações

Stacks são utilizadas em:
  * Operações de desfazer/refazer: a feature desfazer/refazer utiliza stacks para rastrear as ações anteriores. Cada vez que uma ação é executada, ela é colocada na stack. Para desfazer a ação, o elemento do topo da stack é removido.
  * Histórico do navegador: os navegadores utilizam stacks para rastrear as páginas que visitamos. Cada vez que visitamos uma nova página, a URL é colocada na stack, e quando pressionamos o botão de voltar, a URL é removida da stack.

### 3. Termos

* Top: é o elemento no topo da stack, que mantemos uma referência para realizar as operações na stack.

### 4. Operações Básicas

* Push: inserir um elemento na stack;
* Pop: remover um elemento da stack;
* Top: retorna o elemento do topo da stack;
* Is Empty: retorna se a stack está vazia;
* Size: retorna o tamanho da stack.

### 5. Complexidade

| Operações | Complexidade |
| ----------| -------------|
| push      | O(1)         |
| pop       | O(1)         |
| top       | O(1)         |
| isEmpty   | O(1)         |
| size      | O(1)         |

> A maioria das operações são O(1) pois em todas elas dependemos apenas do elemento no topo e sempre mantemos uma referência desse elemento no topo

