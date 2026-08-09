#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void inicializarLista(Lista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
}

int listaVazia(Lista *lista){
    return(lista->inicio == NULL);
}

void inserirInicio(Lista *lista, Funcionario funcionario){
    No *novo = (No *) malloc(sizeof(No));

    if(novo == NULL){
        return;
    }

    novo->funcionario = funcionario;

    if(listaVazia(lista)){
        novo->prox = novo;

        lista->inicio = novo;
        lista->fim = novo;
    }else{
        novo->prox = lista->inicio;
        lista->inicio = novo;
        lista->fim->prox = lista->inicio;
    }
}

void inserirFim(Lista *lista, Funcionario funcionario){
    No *novo = (No *) malloc(sizeof(No));

    if(novo == NULL){
        return;
    }

    novo->funcionario = funcionario;

    if(listaVazia(lista)){
        novo->prox = novo;

        lista->inicio = novo;
        lista->fim = novo;
    }else{
        novo->prox = lista->inicio;
        lista->fim->prox = novo;
        lista->fim = novo;
    }
}

void listarFuncionarios(Lista *lista){
    if(listaVazia(lista)){
        printf("\nLista vazia!\n");
        return;
    }

    No *aux = lista->inicio;

    printf("\n===== FUNCIONARIOS =====\n");

    do{
        printf("Codigo: %d\n", aux->funcionario.codigo);
        printf("Nome  : %s\n", aux->funcionario.nome);
        printf("Setor : %s\n", aux->funcionario.setor);
        printf("----------------------\n");

        aux = aux->prox;

    } while(aux != lista->inicio);
}

No *buscarFuncionarios(Lista *lista, int codigo){
    if(listaVazia(lista)){
        return NULL;
    }

    No *aux = lista->inicio;

    do{
        if(aux->funcionario.codigo == codigo){
            return aux;
        }

        aux = aux->prox;
    } while(aux != lista->inicio);

    return NULL;
}

