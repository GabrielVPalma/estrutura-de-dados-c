# Lista Estática:

Implementação de uma lista estática sequencial utilizando a linguagem C.

## Sobre

Este projeto foi desenvolvido como parte dos meus estudos de Estruturas de Dados.

## Conceito

Uma lista estática (ou sequencial) é uma estrutura de dados linear em que os elementos são armazenados em posições contíguas de memória e cujo tamanho máximo é fixado previamente, não podendo crescer ou diminuir durante a execução.

## Operações implementadas

- Inicialização da lista;
- Inserção no final;
- Inserção em uma posição específica;
- Remoção de uma posição;
- Busca de elementos;
- Verificação se a lista está vazia;
- Verificação se a lista está cheia;
- Exibição dos elementos;
- Cálculo da média;
- Identificação da maior nota;
- Identificação da menor nota.

## Representação

Uma lista sequencial estática utiliza um vetor de tamanho fixo para armazenar os elementos em posições consecutivas da memória.

```text
Lista
┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
│ 10 │ 20 │ 30 │ 40 │ 50 │    │    │    │    │    │
└────┴────┴────┴────┴────┴────┴────┴────┴────┴────┴────┘
  0    1    2    3    4    5    6    7    8    9

        elementos utilizados;
        tamanho = 5;
```
