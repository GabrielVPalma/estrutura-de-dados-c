# Lista Circular

Implementação de uma **lista circular em C**.

O projeto demonstra o uso de structs, ponteiros, alocação dinâmica de memória e operações fundamentais de uma lista circular.

## Sobre

Este projeto foi desenvolvido como parte dos meus estudos de Estruturas de Dados.

## Conceito

Uma lista circular é uma estrutura de dados dinâmica em que o último nó não aponta para `NULL`. Em vez disso, ele aponta novamente para o primeiro nó da lista.

Neste projeto, cada nó possui:

- Os dados do funcionário;
- Um ponteiro para o próximo nó (`prox`).
- Ao chegar ao fim, temos um ponteiro para o primeiro elemento, mantendo a circularidade.

A lista mantém ponteiros para o primeiro (`inicio`) e para o último (`fim`) elemento.


Vale ressaltar que a lista circular em questão, por ser simplesmente circular, não possui ponteiro para o nó anterior, como conhecido na duplamente encadeada, sendo assim, a navegação fica mais restrita, porém, o fato de ser circular acaba "compensando" essa questão, tendo a lista sua eficiência em aplicações específicas.

## Operações implementadas

- **Inicialização:** cria uma lista vazia.
- **Verificação de lista vazia:** verifica se a lista possui elementos.
- **Inserção no início:** adiciona um novo funcionário no início da lista.
- **Inserção no final:** adiciona um novo funcionário ao final da lista.
- **Listagem:** percorre a lista e exibe os funcionários.
- **Busca por código:** localiza um funcionário através do código informado.
- **Remoção por código:** remove um funcionário utilizando seu código.
- **Liberação da memória:** libera todos os nós alocados dinamicamente.
- **Reexecução do programa:** permite executar o programa novamente após sua finalização.

## Representação

```text
                    ┌─────────────────────────────┐
                    │                             │
                    ▼                             │
inicio          [Funcionario] → [Funcionario] → [Funcionario]
  │                                                   │
  └───────────────────────────────────────────────────┘
                                                      ↑
                                                     fim
```

A principal característica da estrutura é:

```c
fim->prox == inicio
```

Dessa forma, o último elemento sempre aponta novamente para o primeiro.

### Estrutura de um nó

```text
┌──────────────────────┬────────────────────┐
│     Funcionario      │        prox        │
└──────────────────────┴────────────────────┘
```

---


