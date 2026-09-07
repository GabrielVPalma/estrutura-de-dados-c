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

