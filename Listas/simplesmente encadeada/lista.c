#include <stdio.h>
#include "lista.h"

void inicializarLista(Lista *lista){
    lista->tamanho = 0;
}

int listaVazia(Lista *lista){
    return lista->tamanho == 0;
}

int listaCheia(Lista *lista){
    return lista->tamanho == MAX;
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

int buscarNota(Lista *lista, float nota) {

    for (int i = 0; i < lista->tamanho; i++) {

        if (lista->notas[i] == nota) {
            return i;
        }
    }

    return -1;
}

void imprimirLista(Lista *lista){

    if(listaVazia(lista)){
        printf("A lista esta vazia.\n");
        return;
    }

    printf("\nNotas da lista:\n");

    for(int i = 0; i < lista->tamanho; i++){
        printf("Posicao %d: %.2f\n", i, lista->notas[i]);
    }
}

float calcularMedia(Lista *lista) {

    if (listaVazia(lista)) {
        return 0.0;
    }

    float soma = 0.0;

    for (int i = 0; i < lista->tamanho; i++) {
        soma += lista->notas[i];
    }

    return soma / lista->tamanho;
}


float maiorNota(Lista *lista) {

    if (listaVazia(lista)) {
        return 0.0;
    }

    float maior = lista->notas[0];

    for (int i = 1; i < lista->tamanho; i++) {

        if (lista->notas[i] > maior) {
            maior = lista->notas[i];
        }
    }

    return maior;
}


float menorNota(Lista *lista) {

    if (listaVazia(lista)) {
        return 0.0;
    }

    float menor = lista->notas[0];

    for (int i = 1; i < lista->tamanho; i++) {

        if (lista->notas[i] < menor) {
            menor = lista->notas[i];
        }
    }

    return menor;
}