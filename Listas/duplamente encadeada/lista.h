#ifndef LISTA_H
#define LISTA_H

typedef struct
{
    int codigo;
    char titulo[100];
    char autor[50];
    int ano;
} Livro;

typedef struct No 
{
    Livro livro;
    struct No *ant;
    struct No *prox;
} No;

typedef struct 
{
    No *inicio;
    No *fim;
} Lista;

void inicializarLista(Lista *lista);

int listaVazia(Lista *lista);

void inserirInicio(Lista *lista, Livro livro);

void inserirFim(Lista *lista, Livro livro);

void listarInicioFim(Lista *lista);

void listarFimInicio(Lista *lista);

No *buscarLivro(Lista *lista, int codigo);

void liberarLista(Lista *lista);

#endif