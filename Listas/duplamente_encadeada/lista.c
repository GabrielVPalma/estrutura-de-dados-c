#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void inicializarLista(Lista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
}

int listaVazia(Lista *lista){
    return (lista->inicio == NULL);
}

void inserirInicio(Lista *lista, Livro livro){
    No *novo = (No *) malloc(sizeof(No));

    if(novo == NULL){
        return;
    }

    novo->livro = livro;
    novo->ant = NULL;
    novo->prox = lista->inicio;

    if(listaVazia(lista)){
        lista->inicio = novo;
        lista->fim = novo;
    }else{
        lista->inicio->ant = novo;
        lista->inicio = novo;
    }
}

void inserirFim(Lista *lista, Livro livro){
    No *novo = (No *) malloc(sizeof(No));

    if(novo == NULL){
        return;
    }

    novo->livro = livro;
    novo->prox = NULL;
    novo->ant = lista->fim;

    if(listaVazia(lista)){
        lista->inicio = novo;
        lista->fim = novo;
    }else{
        lista->fim->prox = novo;
        lista->fim = novo;
    }
}

void listarInicioFim(Lista *lista){
    No *aux = lista->inicio;

    if(listaVazia(lista)){
        printf("\nLista vazia!\n");
        return;
    }

    printf("\n==== LIVROS DO INICIO AO FIM ====\n\n");

    while(aux != NULL){
        printf("Codigo: %d\n", aux->livro.codigo);
        printf("Titulo: %s\n", aux->livro.titulo);
        printf("Autor : %s\n", aux->livro.autor);
        printf("Ano   : %d\n", aux->livro.ano);
        printf("-----------------------------\n");

        aux = aux->prox;
    }
}

void listarFimInicio(Lista *lista)
{
    No *aux = lista->fim;

    if (listaVazia(lista))
    {
        printf("\nLista vazia!\n");
        return;
    }

    printf("\n===== LIVROS (FIM -> INICIO) =====\n\n");

    while (aux != NULL)
    {
        printf("Codigo: %d\n", aux->livro.codigo);
        printf("Titulo: %s\n", aux->livro.titulo);
        printf("Autor : %s\n", aux->livro.autor);
        printf("Ano   : %d\n", aux->livro.ano);
        printf("-----------------------------\n");

        aux = aux->ant;
    }
}

No *buscarLivro(Lista *lista, int codigo){
    No *aux = lista->inicio;

    while(aux != NULL){
        if(aux->livro.codigo == codigo){
            return aux;
        }

        aux = aux->prox;
    }

    return NULL;
}

int removerLivro(Lista *lista, int codigo){
    No *aux = buscarLivro(lista, codigo);

    if(aux == NULL){
        return 0;
    }

    if(aux == lista->inicio && aux == lista->fim){
        lista->inicio = NULL;
        lista->fim = NULL;
    }else if(aux == lista->inicio){
        lista->inicio = aux->prox;
        lista->inicio->ant = NULL;
    }else if(aux == lista->fim){
        lista->fim = aux->ant;
        lista->fim->prox = NULL;
    }else{
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
    }

    free(aux);

    return 1;
}

void liberarLista(Lista *lista){
    No *aux = lista->inicio;

    while(aux != NULL){
        No *temp = aux;
        aux = aux->prox;
        free(temp);
    }

    lista->inicio = NULL;
    lista->fim = NULL;
}