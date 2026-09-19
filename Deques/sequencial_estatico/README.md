# Deque Sequencial Estático

Implementação de um **Deque Sequencial Estático em C**.

O projeto utiliza um vetor de tamanho fixo para armazenar os elementos, demonstrando as principais operações de um **Deque (Double-Ended Queue)**.

## Sobre

Este projeto foi desenvolvido como parte dos meus estudos de Estruturas de Dados.

## Conceito

Um deque, abreviação de **Double-Ended Queue**, é uma estrutura de dados linear que permite a **inserção e remoção de elementos pelas duas extremidades**.

Seguindo o princípio: 

> **Double-Ended Queue - fila de duas extremidades** 

Diferentemente de uma fila tradicional, que normalmente realiza a inserção no final e a remoção no início, o deque permite operações em ambos os lados.

As principais operações podem ser representadas da seguinte forma:

```text
                  DEQUE

            INÍCIO       FIM
              ↓           ↓
              ↕           ↕
          inserir      inserir
          remover      remover
```

Por exemplo, considerando a situação de clientes, podemos inserir ou remover um cliente no início ou no fim:

```text
┌────────┬────────┬────────┬────────┬────────┐
│ Pedro  │ João   │ Maria  │ Carlos │ Ana    │
└────────┴────────┴────────┴────────┴────────┘
  ↑                                      ↑
INÍCIO                                  FIM
```

## Operações implementadas

- **Inicialização**: cria um deque vazio, definindo `inicio` e `fim` como 0.
- **inserirInicio**: adiciona um novo cliente no início do deque, deslocando os elementos existentes uma posição para a direita.
- **inserirFim**: adiciona um novo cliente no final do deque.
- **removerInicio**: remove e retorna o primeiro cliente do deque, deslocando os elementos restantes uma posição para a esquerda.
- **removerFim**: remove e retorna o último cliente do deque.
- **frente**: consulta o primeiro cliente sem removê-lo.
- **tras**: consulta o último cliente sem removê-lo.
- **Verificação de deque vazio**: verifica se `inicio == fim`.
- **Verificação de deque cheio**: verifica se o limite máximo do vetor foi atingido.
- **Listagem**: exibe todos os clientes armazenados no deque.
- **Limpeza**: remove logicamente todos os elementos do deque.
- **Validação de entrada**: trata entradas inválidas no menu e opções fora do intervalo permitido.

Foi implementado também um menu interativo que oferece uma experiência segura e prática ao usuário, com validações de segurança para evitar leituras indesejadas e comportamentos inesperados do programa caso sejam inseridos valores diferentes dos esperados.

## Overflow e Underflow

Foram representadas duas situações importantes em estruturas de dados.

### Overflow

Ocorre quando tentamos inserir um elemento em um **deque que já está cheio**.

```text
Deque cheio

     ↓

inserirInicio()
ou
inserirFim()

     ↓

 OVERFLOW
 ```

Nesse caso, as funções `inserirInicio()` e `inserirFim()` retornam 0 e o **elemento não é inserido**, uma mensagem de erro também é exibida ao usuário, informando que o limite máximo do deque foi atingido.

### Underflow

Ocorre quando tentamos remover um elemento de um **deque vazio**.

```text
Deque vazio

     ↓

removerInicio()
ou
removerFim()

     ↓

 UNDERFLOW
 ```

Nesse caso, as funções `removerInicio()` e `removerFim()` retornam 0, uma mensagem de erro também é exibida ao usuário, informando que o deque está vazio.

## Representação da estrutura 

A implementação utiliza um vetor de tamanho fixo e duas variáveis para controlar as extremidades:

- **inicio**: indica a posição do primeiro elemento do deque.
- **fim**: indica a posição seguinte ao último elemento armazenado.

A estrutura pode ser representada da seguinte forma, considerando um deque com três clientes:

```text
INÍCIO                         FIM
  ↓                             ↓

┌────────┬────────┬────────┬────────┬────────┐
│ João   │ Maria  │ Carlos │        │        │
└────────┴────────┴────────┴────────┴────────┘
  0        1        2        3        4
```

Nesse momento, inicio = 0 e fim = 3.

> **O fim representa a próxima posição livre, e não a posição do último elemento**.

Por isso, o último elemento está localizado em fim - 1:

fim = 3;
fim - 1 = 2 (Carlos);

Este projeto utiliza um **Deque Sequencial Estático**, portanto os elementos são armazenados em um vetor de **tamanho fixo**.

Uma característica importante é que as operações realizadas no início podem exigir o **deslocamento dos elementos**.

Essa característica faz com que operações nas extremidades não tenham necessariamente o mesmo custo, em implementações futuras, outras abordagens, como estruturas circulares ou dinâmicas, podem ser utilizadas para reduzir algumas dessas limitações.

### Inserção no início

Uma das particularidades deste deque é a inserção no início.

Considere:

```text
INÍCIO                 FIM
  ↓                     ↓

┌────────┬────────┬────────┐
│ João   │ Maria  │ Carlos │
└────────┴────────┴────────┘
```

Ao inserir Pedro no início, os elementos existentes precisam ser deslocados uma posição para a direita:

```text
┌────────┬────────┬────────┬────────┐
│        │ João   │ Maria  │ Carlos │
└────────┴────────┴────────┴────────┘
```

Depois, Pedro é colocado na posição inicial:

```text
INÍCIO                         FIM
  ↓                             ↓

┌────────┬────────┬────────┬────────┐
│ Pedro  │ João   │ Maria  │ Carlos │
└────────┴────────┴────────┴────────┘
```

- Essa operação é necessária porque a implementação utiliza um vetor sequencial.

### Remoção do início

A remoção no início funciona de maneira semelhante.

Considere:

```text
INÍCIO                         FIM
  ↓                             ↓

┌────────┬────────┬────────┬────────┐
│ Pedro  │ João   │ Maria  │ Carlos │
└────────┴────────┴────────┴────────┘
```

Ao remover Pedro, os elementos restantes são deslocados uma posição para a esquerda:

```text
INÍCIO                 FIM
  ↓                     ↓

┌────────┬────────┬────────┐
│ João   │ Maria  │ Carlos │
└────────┴────────┴────────┘
```

- Dessa forma, o primeiro elemento continua ocupando a posição indicada por `inicio`.

## Funcionamento do programa

O programa apresenta um menu interativo, permitindo um fácil entendimento ao usuário:

```text
===== DEQUE DE ATENDIMENTO =====

1 - Adicionar cliente no inicio
2 - Adicionar cliente no fim
3 - Atender cliente do inicio
4 - Remover cliente do fim
5 - Ver primeiro cliente
6 - Ver ultimo cliente
7 - Listar deque
8 - Verificar se o deque esta vazio
9 - Verificar se o deque esta cheio
10 - Limpar deque
0 - Sair
```

## Exemplo

Inicialmente, o deque está vazio:

```text
┌────────┬────────┬────────┬────────┬────────┐
│        │        │        │        │        │
└────────┴────────┴────────┴────────┴────────┘
```

Ao selecionar:

1 - Adicionar cliente no inicio

e inserir João:

```text
┌────────┬────────┬────────┬────────┬────────┐
│ João   │        │        │        │        │
└────────┴────────┴────────┴────────┴────────┘
```

Depois, selecionando:

2 - Adicionar cliente no fim

e inserindo Maria:

```text
┌────────┬────────┬────────┬────────┬────────┐
│ João   │ Maria  │        │        │        │
└────────┴────────┴────────┴────────┴────────┘
```

Agora podemos adicionar Carlos novamente no início:

```text
┌────────┬────────┬────────┬────────┬────────┐
│ Carlos │ João   │ Maria  │        │        │
└────────┴────────┴────────┴────────┴────────┘
```

E Ana no fim:

```text
┌────────┬────────┬────────┬────────┬────────┐
│ Carlos │ João   │ Maria  │ Ana    │        │
└────────┴────────┴────────┴────────┴────────┘
```

O deque permite então remover elementos de qualquer uma das extremidades.

Ao selecionar:

3 - Atender cliente do inicio

Carlos será removido:

```text
┌────────┬────────┬────────┐
│ João   │ Maria  │ Ana    │
└────────┴────────┴────────┘
```

Enquanto ao selecionar:

4 - Remover cliente do fim

Ana será removida:

```text
┌────────┬────────┐
│ João   │ Maria  │
└────────┴────────┘
```

## Conceitos praticados

- Linguagem C
- Estruturas (`struct`)
- Vetores
- Ponteiros
- Ponteiros para estruturas
- Strings
- `fgets()`
- `scanf()`
- `getchar()`
- `strcspn()`
- Validação de entrada
- Estruturas sequenciais
- Deque **(Double-Ended Queue)**
- Inserção no início
- Inserção no fim
- Remoção no início
- Remoção no fim
- Controle de inicio e fim
- Overflow e Underflow
- Separação entre arquivos `.h` e `.c`
- Compilação utilizando GCC

## Conclusão

O projeto foi importante para reforçar, na prática, o funcionamento de um Deque Sequencial Estático, suas principais operações e a possibilidade de manipular elementos pelas duas extremidades.

Além disso, permitiu praticar o controle das posições de inicio e fim, a inserção e remoção de elementos no início e no fim, o tratamento de situações de overflow e underflow, a manipulação de estruturas e ponteiros, a separação do código em arquivos .h e .c e a construção de um menu interativo com validação de entrada.

A implementação também permitiu compreender o funcionamento de um deque utilizando um vetor de tamanho fixo e a necessidade de realizar deslocamentos durante algumas operações.