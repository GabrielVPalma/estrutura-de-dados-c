#ifndef LISTA_H
#define LISTA_H

typedef struct
{
    int codigo;
    char nome[50];
    float preco;
} Produto;

typedef struct No
{
    Produto produto;
    struct No *prox;
} No;

typedef struct 
{
    No *inicio;
} Lista;

void inicializarLista(Lista *lista);

int listaVazia(Lista *lista);

void inserirInicio(Lista *lista, Produto produto);

void inserirFim(Lista *lista, Produto produto);

void listarProdutos(Lista *lista);

No *buscarProduto(Lista *lista, int codigo);

int removerProduto(Lista *lista, int codigo);

void liberarLista(Lista *lista);

#endif