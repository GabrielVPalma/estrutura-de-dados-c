# Pilha Sequencial Estática

Implementação de uma **Pilha Estática em C**.

O projeto utiliza um vetor de tamanho fixo para armazenar os elementos demonstrando as principais operações de uma PILHA.

## Sobre

Este projeto foi desenvolvido como parte dos meus estudos de Estruturas de Dados.

## Conceito

Uma pilha é uma estrutura de dados linear que segue o princípio:

> **LIFO — Last In, First Out**

- Isso significa que o **último elemento inserido** será o **primeiro a ser removido**.
- Um exemplo prático e comum para definir pilha é o histórico de ações de um programa, com a possiblidade de desfazer a última ação realizada.

Por exemplo, considerando as ações:

```text
1. Digitou um texto
2. Salvou o arquivo
3. Alterou o título
```

A pilha será representada da seguinte forma:

```text
              TOPO
               ↓
        ┌──────────────────┐
        │  Alterou título  │
        ├──────────────────┤
        │  Salvou arquivo  │
        ├──────────────────┤
        │  Digitou texto   │
        └──────────────────┘
```

Ao realizar uma operação de `pop`, a ação **"Alterou título"** será removida primeiro.

## Operações implementadas

- **Inicialização:** cria uma pilha vazia, definindo `topo` como `-1`.
- **`push`:** adiciona uma nova ação no topo da pilha.
- **`pop`:** remove e retorna a ação que está no topo.
- **`top`:** consulta a ação que está no topo sem removê-la.
- **Verificação de pilha vazia:** verifica se `topo == -1`.
- **Verificação de pilha cheia:** verifica se o limite máximo da pilha foi atingido.
- **Listagem:** exibe todas as ações armazenadas na pilha.
- **Limpeza:** remove logicamente todos os elementos da pilha.
- **Validação de entrada:** trata entradas inválidas no menu e opções fora do intervalo permitido.

Vale destacar também a implementação de um menu que oferece uma interação segura com o usuário, com "filtros" reforçados para respostas, evitando leituras indesejadas e bugs do programa caso algo diferente das opções oferecidas seja inserido. 

## Overflow e Underflow 

Foram representadas duas situações importantes em estrutura de dados.

### Overflow

Ocorre quando tentamos inserir um elemento em uma **pilha que já está cheia**.

```text
Pilha cheia
     ↓
   push()
     ↓
  OVERFLOW
```

Nesse caso, a função `push()` retorna `0` e o elemento não é inserido.
Uma mensagem de erro também é exibida ao usuário, informando sobre o limite atingido.

### Underflow

Ocorre quando tentamos remover um elemento de uma pilha vazia.

```text
Pilha vazia
     ↓
   pop()
     ↓
  UNDERFLOW
```

Nesse caso, a função `pop()` retorna `0`.
Uma mensagem de erro também é exibida ao usuário, informando que a pilha está vazia.

## Representação da estrutura

A implementação utiliza um vetor de tamanho fixo e uma variável `topo` para controlar a posição do último elemento inserido.

```text
Pilha

┌───────────────────┐
│       dados[9]    │
├───────────────────┤
│       dados[8]    │
├───────────────────┤
│        ...        │
├───────────────────┤
│       dados[2]    │
├───────────────────┤
│       dados[1]    │
├───────────────────┤
│       dados[0]    │
└───────────────────┘
          ↑
         topo
```

Quando a pilha está vazia:

```text
topo = -1
```

Após a inserção do primeiro elemento:

```text
topo = 0
```

Após a inserção do segundo:

```text
topo = 1
```

E assim sucessivamente, até o topo ser o último elemento inserido...

## Funcionamento do programa

O programa apresenta um menu interativo:

```text
===== HISTORICO DE ACOES =====

1 - Adicionar acao
2 - Desfazer ultima acao
3 - Consultar ultima acao
4 - Listar historico
5 - Limpar historico
0 - Sair
```

### Exemplo

Ao adicionar:

```text
Digitou um texto
Salvou o arquivo
Alterou o titulo
```

a pilha ficará:

```text
        TOPO
          ↓
┌────────────────────┐
│ Alterou o titulo   │
├────────────────────┤
│ Salvou o arquivo   │
├────────────────────┤
│ Digitou um texto   │
└────────────────────┘
```

Ao selecionar:

```text
2 - Desfazer ultima acao
```

o programa executará `pop()` e removerá:

```text
Alterou o titulo
```

A pilha passará a ser:

```text
        TOPO
          ↓
┌────────────────────┐
│ Salvou o arquivo   │
├────────────────────┤
│ Digitou um texto   │
└────────────────────┘
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
- Validação de entrada
- Estruturas sequenciais
- Pilha LIFO
- Gerenciamento do topo da pilha
- Overflow e Underflow
- Separação entre arquivos `.h` e `.c`
- Compilação utilizando GCC

## Conclusão

O projeto apresentou extrema importância para reforçar na prática o funcionamento de uma Pilha Sequencial Estática, suas funções e comportamento, controle do topo e o tratamento de situações de overflow e underflow, tal como, construção de um menu interativo seguro e de fácil compreensão ao usuário.