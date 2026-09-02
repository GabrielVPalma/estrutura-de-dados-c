#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void inicializarLista(Lista *lista){
    lista->inicio = NULL;
}

int listaVazia(Lista *lista){
    return lista->inicio == NULL;
}

void inserirInicio(Lista *lista, Produto produto){
    No *novo = malloc(sizeof(No));

    if(novo == NULL){
        printf("Erro ao alocar memoria.\n");
        return;
    }

    novo->produto = produto;
    novo-> prox = lista->inicio;

    lista->inicio = novo;
}

void inserirFim(Lista *lista, Produto produto){
    No *novo = malloc(sizeof(No));

    if(novo == NULL){
        printf("Erro ao alocar memoria.\n");
        return;
    }

    novo->produto = produto;
    novo->prox = NULL;

    if(lista->inicio == NULL){
        lista->inicio = novo;
        return;
    }

    No *atual = lista->inicio;

    while(atual->prox != NULL){
        atual = atual->prox;
    }
    atual->prox = novo;
}

void listarProdutos(Lista *lista){
    No *atual = lista->inicio;

    if(atual == NULL){
        printf("A lista esta vazia.\n");
        return;
    }

    printf("\n==== PRODUTOS ====\n");

    while(atual != NULL){
        printf("Codigo: %d\n", atual->produto.codigo);
        printf("Nome: %s\n", atual->produto.nome);
        printf("Preco: R$ %.2f\n", atual->produto.preco);
        printf("--------------\n");

        atual = atual->prox;
    }
}

No *buscarProduto(Lista *lista, int codigo){
    No *atual = lista->inicio;

    while(atual != NULL){
        if(atual->produto.codigo == codigo){
            return atual;
        }

        atual = atual->prox;
    }

    return NULL;
}

int removerProduto(Lista *lista, int codigo){
    No *atual = lista->inicio;
    No *anterior = NULL;

    while(atual != NULL && atual->produto.codigo != codigo){
        anterior = atual;
        atual = atual->prox;
    }

    if(atual == NULL){
        return 0;
    }
    
    if(anterior == NULL){ //Elemento a ser removido é o primeiro;
        lista->inicio = atual->prox;
    }else{ //Elemento a ser removido está no meio ou fim da lista;
        anterior->prox = atual->prox;
    }

    free(atual);
    return 1;
}

void liberarLista(Lista *lista){
    No *atual = lista->inicio;

    while(atual != NULL){
        No *proximo = atual->prox;

        free(atual);

        atual = proximo;
    }
    
    lista->inicio = NULL;
}