# Lista Simplesmente Encadeada

Implementação de uma **lista simplesmente encadeada em C**.

O projeto demonstra o uso de structs, ponteiros, alocação dinâmica de memória e operações básicas em uma lista encadeada.

## Sobre

Este projeto foi desenvolvido como parte dos meus estudos de Estruturas de Dados.

## Conceito

Uma lista simplesmente encadeada é uma estrutura de dados formada por nós.

Cada nó possui:

- Os dados armazenados;
- Um ponteiro para o próximo nó.

## Operações implementadas

- **Inicialização:** cria uma lista vazia;
- **Verificação de lista vazia:** verifica se a lista não possui elementos;
- **Inserção no início:** adiciona um novo elemento na primeira posição da lista;
- **Inserção no final:** adiciona um novo elemento ao final da lista;
- **Listagem:** percorre a lista e exibe os dados de todos os produtos;
- **Busca por código:** procura um produto na lista a partir do seu código;
- **Remoção por código:** remove um produto da lista utilizando seu código;
- **Liberação da memória:** libera a memória alocada para os nós da lista;
- **Reexecução do programa:** permite ao usuário executar o programa novamente após finalizar as operações.

Além das operações, o main foi feito pensando em permitir uma maior interação com o usuário, fornecendo opções para navegação.

## Representação

A estrutura pode ser representada da seguinte forma:

```text
[inicio]
   |
   v
[Produto | *] -> [Produto | *] -> [Produto | NULL]
```

