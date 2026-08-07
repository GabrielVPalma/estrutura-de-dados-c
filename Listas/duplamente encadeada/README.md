# Lista Duplamente encadeada

Implementação de uma **lista duplamente encadeada em C**.

O projeto demonstra o uso de structs, ponteiros, alocação dinâmica de memória e operações fundamentais de uma lista duplamente encadeada, permitindo a navegação tanto do início para o fim quanto do fim para o início.

## Sobre

Este projeto foi desenvolvido como parte dos meus estudos de Estruturas de Dados.

## Conceito

Uma lista duplamente encadeada é uma estrutura de dados dinamica composta por nós, cada nó possui/armazena:

- Dados do elemento;
- Um ponteiro para o nó anterior ('ant');
- Um ponteiro para o próximo nó ('prox');

A lista mantém ponteiros para o primeiro (`inicio`) e para o último (`fim`) elemento.


A principal diferença para com a simplesmente encadeada é justamente a possibilidade de acessar o elemento anterior pelo ponteiro 'ant', aumentando a utilização e possibilidades da lista.

## Operações Implementadas

- **Inicialização:** cria uma lista vazia.
- **Verificação de lista vazia:** verifica se a lista possui elementos.
- **Inserção no início:** adiciona um novo livro no início da lista.
- **Inserção no final:** adiciona um novo livro ao final da lista.
- **Listagem (Início → Fim):** percorre a lista do primeiro ao último elemento.
- **Listagem (Fim → Início):** percorre a lista do último ao primeiro elemento.
- **Busca por código:** localiza um livro através do código informado.
- **Remoção por código:** remove um livro da lista utilizando seu código.
- **Liberação da memória:** libera todos os nós alocados dinamicamente.
- **Reexecução do programa:** permitindo executar novamente o exemplo após sua finalização.

## Representação 

A estrutura pode ser representada da seguinte forma: 

```text
                    Lista:


inicio
  │
  ▼

NULL ← [Livro] ⇄ [Livro] ⇄ [Livro] ⇄ [Livro] → NULL

                                             ▲
                                             │
                                            fim
```

Cada nó possui a seguinte estrutura:

```text
┌───────────────┬──────────────────┬───────────────┐
│      ant      │      Livro       │     prox      │
└───────────────┴──────────────────┴───────────────┘
```
