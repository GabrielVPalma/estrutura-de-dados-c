#include <stdio.h>
#include "lista.h"

void inicializarLista(Lista *lista){
    lista->tamanho = 0;
}

int listaVazia(Lista *lista){
    return lista->tamanho == 0;
}

int listaCheia(Lista *lista){
    return lista->tamnho == MAX;
}

int inserirFinal(Lista *lista, float nota){

    if (listaCheia(lista)){
        return 0;
    }

    lista->notas[lista->tamanho] = nota;
    lista->tamanho++;
    
    return 1;
}

int inserirPosicao(Lista *lista, float nota, int posicao){

    if(listaCheia(lista)){
        return 0;
    }
    
    if(posicao < 0 || posicao > lista->tamanho){
        return 0;
    }

    for(int i = lista->tamanho; i > posicao; i--){
        lista->notas[i] = lista->notas[i - 1];
    }

    lista->notas[posicao] = nota;
    lista->tamanho++;

    return 1;
}

int removerPosicao(Lista *lista, int posicao){
    
    if(listaVazia(lista)){
        return 0;
    }

    if(posicao < 0 || posicao >= lista->tamanho){
        return 0;
    }

    for(int i = posicao; i < lista->tamanho - 1; i++){
        lista->notas[i] = lista->notas[i + 1];
    }

    lista->tamanho--;

    return 1;
}

