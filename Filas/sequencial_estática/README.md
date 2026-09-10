# Fila Sequencial Estática

Implementação de uma **Fila Sequencial Estática em C**.

O projeto utiliza um vetor de tamanho fixo para armazenar os elementos, demonstrando as principais operações de uma FILA e seu funcionamento na prática.

## Sobre

Este projeto foi desenvolvido como parte dos meus estudos de Estruturas de Dados.

## Conceito

Uma fila é uma estrutura de dados linear que segue o princípio:

> **FIFO - First In, First Out**

Isso significa que o **primeiro elemento inserido** será o **primeiro elemento a ser removido**, assim como filas do cotidiano.

Um exemplo prático para representar uma fila é uma **fila de atendimento**, onde os clientes são atendidos na mesma ordem em que chegaram.

Por exemplo, considerendo os clientes:

```text
1. João
2. Maria
3. Carlos

A fila será representada da seguinte forma:

INÍCIO                         FIM
  ↓                             ↓

┌──────────────────┐
│ João             │
├──────────────────┤
│ Maria            │
├──────────────────┤
│ Carlos           │
└──────────────────┘

```

Nesse caso, João será o primeiro cliente a ser atendido, pois foi o primeiro a entrar na fila.

Ao realizar a operação de **desenfileirar**, o cliente João será removido primeiro.

## Operações Implementadas

- **Inicialização**: cria uma fila vazia, definindo `inicio` e `fim` como 0.
- **enfileirar**: adiciona um novo cliente ao final da fila.
- **desenfileirar**: remove e retorna o primeiro cliente da fila.
- **frente**: consulta o primeiro cliente da fila sem removê-lo.
- **Verificação de fila vazia**: verifica se `inicio == fim`.
- **Verificação de fila cheia**: verifica se `fim == MAX`.
- **Listagem**: exibe todos os clientes atualmente armazenados na fila.
- **Limpeza**: remove logicamente todos os elementos da fila, reiniciando inicio e fim.
- **Validação de entrada**: trata entradas inválidas no menu e opções fora do intervalo permitido.

Foi implementado também um menu interativo que oferece uma experiência segura e prática ao usuário, com validações de segurança para evitar leituras indesejadas e comportamentos inesperados do programa caso sejam inseridos valores diferentes dos esperados.

## Overflow e Underflow 

Foram representadas duas situações importantes em estrutura de dados.

### Overflow

Ocorre quando tentamos inserir um elemento em uma fila que já está cheia, nesse caso a função **enfileirar** retornará 0 e o novo cliente não é inserido:

```text
Fila cheia

     ↓

enfileirar()

     ↓

 OVERFLOW
```

Uma mensegem de limite máximo atingido também é exibida ao usuário.

### Underflow

Ocorre quando tentamos remover um elemento de uma fila vazia, nesse caso a função **desenfileirar** retornará também 0:

```text
Fila vazia

     ↓

desenfileirar()

     ↓

 UNDERFLOW
```

Uma mensagem de erro é exibida ao usuário informando a situação (vazia) da fila.

## Representação da estrutura

A estrutura é composta por um vetor de tamanho fixo e duas variáveis responsáveis por controlar a fila:

- `inicio`: indica a posição do primeiro elemento da fila.
- `fim`: indica a posição onde o próximo elemento será inserido.

```text
Fila

┌────────────────────┐
│ elementos[0]       │
├────────────────────┤
│ elementos[1]       │
├────────────────────┤
│ elementos[2]       │
├────────────────────┤
│ elementos[3]       │
├────────────────────┤
│ elementos[4]       │
└────────────────────┘
```

No caso: 

```text
INÍCIO (0)              FIM (3)
  ↓                      |
                         |
┌────────────────────┐   |
│ João               │   |
├────────────────────┤   |
│ Maria              │   |
├────────────────────┤   |
│ Carlos             │   |
├────────────────────┤   |
│                    │  <-
├────────────────────┤
│                    │
└────────────────────┘
```

Significa dizer que o primeiro cliente está na posição 0, e o próximo elemento (que representará o **fim** da lista) será inserido na posição 3.

Vale destacar que quando a fila está vazia, inicio e fim indicam a posição 0, sendo o fim atualizado conforme inserções.

## Funcionamento do programa

O programa apresenta um menu interativo, permitindo um fácil entendimento ao usuário:

```text
===== FILA DE ATENDIMENTO =====

1 - Adicionar cliente
2 - Atender cliente
3 - Ver proximo cliente
4 - Listar fila
5 - Verificar se a fila esta vazia
6 - Verificar se a fila esta cheia
7 - Limpar fila
0 - Sair
```

### Exemplo

Ao adicionar os clientes: 

Senha: 101
Nome: João

Senha: 102
Nome: Maria

Senha: 103
Nome: Carlos

A estrutura da fila ficará:

```text
             INÍCIO                         
                ↓  
        ┌────────────────────┐
        │ Senha: 101 | João  │
        ├────────────────────┤
        │ Senha: 102 | Maria │
        ├────────────────────┤
        │ Senha: 103 | Carlos│
        └────────────────────┘
```

Ao selecionar: 2 - Atender cliente, o programa executará **desenfileirar** e removerá o primeiro que estava na fila, nesse caso, João com a senha 101.

A fila passará a ser:

```text
             INÍCIO              
                ↓                   

        ┌────────────────────┐
        │ Senha: 102 | Maria │
        ├────────────────────┤
        │ Senha: 103 | Carlos│
        └────────────────────┘
```

O próximo cliente a ser atendido e removido será Maria, mantendo o princípio **FIFO**.

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
- Fila **FIFO**
- Controle de inicio e fim
- Overflow e Underflow
- Separação entre arquivos `.h` e `.c`
- Compilação utilizando GCC

## Conclusão

O projeto foi importante para reforçar, na prática, o funcionamento de uma Fila Sequencial Estática, suas principais operações e o comportamento baseado no princípio **FIFO**. A implementação também permitiu compreender uma limitação importante das filas sequenciais estáticas, ela pode deixar posições livres no início do vetor sem conseguir reutilizá-las, fazendo com que a fila seja considerada cheia antes de todo o espaço do vetor estar efetivamente ocupado, servindo como base para o estudo de estruturas mais avançadas, como a Fila Circular, Fila Dinâmica e posteriormente o Deque.
